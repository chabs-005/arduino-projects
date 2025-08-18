// libraries
#include <LiquidCrystal.h>

// variables
bool buttonState = LOW;
bool reading = LOW;
bool lastReading = LOW;
const int button_pin = 6;
const int led_pin = 9;

unsigned long lastDebounceTime = 0;
const unsigned long debounceDelay = 50;
unsigned long timer;
unsigned long result_time;
unsigned long start_timer;

unsigned long gameTime; // inizio del gioco

// flags
bool led_on = false;
bool messaggioMostrato = false;

// objects
LiquidCrystal lcd(12,11,5,4,3,2);

// gestione stati
enum statoGioco {
  ATTESA_INIZIO,
  ATTESA_RANDOM,
  REACTION,
  RISULTATO,
  RIAVVIO
};

statoGioco stato = ATTESA_INIZIO;

void setup(){
  lcd.begin(16,2);
  pinMode(led_pin,OUTPUT);
  pinMode(button_pin,INPUT);
  randomSeed(analogRead(A0)); // gestione seme numeri pseudo casuali
}

void loop(){
  unsigned long current_time = millis();
  switch (stato) {
      case ATTESA_INIZIO:
        reading = digitalRead(button_pin);
          // controllo stato bottone
          if(reading != lastReading){
              lastDebounceTime = current_time;
          }
          if(current_time - lastDebounceTime > debounceDelay){
            if(reading != buttonState){
                buttonState = reading;
                  if(!led_on && buttonState == HIGH){
                      lcd.clear();
                      lcd.setCursor(0,0);
                      lcd.print("AVVIO TIMER");
                      timer = random(2000,5000); // timer randomico tra 2 e 5 secondi
                      start_timer = current_time;
                      led_on = true;
                  }
            }
            if(led_on){
               stato = ATTESA_RANDOM;
            }
          }
        lastReading = reading; // aggiornamento stato bottone
        break;
    
    case ATTESA_RANDOM: 
        if(current_time - start_timer >= timer){
              lcd.setCursor(0,0);
              lcd.print("PREMERE ORA");
              digitalWrite(led_pin,HIGH); // accensione led
              gameTime = current_time; // inizio tempo di gioco
              stato = REACTION;
          }
        break;
    
    case REACTION:
        // controllo stato bottone
          reading = digitalRead(button_pin);
        if(reading != lastReading){
              lastDebounceTime = current_time;
          }
          if(current_time - lastDebounceTime > debounceDelay){
            if(reading != buttonState){
                buttonState = reading;
      
                  if(buttonState == HIGH){
                      result_time = current_time - gameTime; // tempo impiegato
                      led_on = false;
                      digitalWrite(led_pin, LOW); // spegnimento led
                    stato = RISULTATO;
                  }
            }
        }
        lastReading = reading; // aggiornamento stato bottone
        break;
    
    case RISULTATO:
        lcd.clear();
        lcd.setCursor(0,0);
        lcd.print("Tempo:");
        lcd.setCursor(0,1);
        lcd.print(result_time);
        lcd.print(" ms");
        delay (5000);
        stato = RIAVVIO;
    
    case RIAVVIO:
             if (!messaggioMostrato) {
                lcd.clear();
                lcd.setCursor(0,0);
                lcd.print("PREMERE BOTTONE");
                lcd.setCursor(0,1);
                lcd.print("PER RIAVVIARE");
                messaggioMostrato = true;  // così non riscrive più
              }

              reading = digitalRead(button_pin);
              if (reading != lastReading) {
                lastDebounceTime = current_time;
              }
              if (current_time - lastDebounceTime > debounceDelay) {
                if (buttonState != reading) {
                  buttonState = reading;
                      if (buttonState == HIGH) { 
                           stato = ATTESA_INIZIO;
                           messaggioMostrato = false; // reset messaggio per la prossima volta
                      }
                }
              }
        	  lastReading = reading; // aggiornamento stato bottone
            break;
 	 }
}
