# Reaction Time Game

A fun and interactive Arduino-based game that tests your reaction time! Challenge yourself to respond as quickly as possible when the signal appears.

## 📝 Project Overview

This project implements a reaction time testing game using an Elegoo UNO R3. The game displays instructions on an LCD screen, waits for a random period (2-5 seconds), then signals the player with both a visual LED cue and screen message. The player must press a button as quickly as possible, and their reaction time is measured and displayed.

## 🎯 Features

- **LCD Display Interface**: Clear 16x2 LCD showing game status, instructions, and results
- **Visual Cue System**: LED indicator that lights up when it's time to react
- **Random Timing**: Unpredictable wait times between 2-5 seconds to prevent anticipation
- **Precise Timing**: Accurate reaction time measurement in milliseconds
- **User-Friendly Controls**: Single button interface for easy interaction
- **Adjustable Display**: Potentiometer for fine-tuning LCD contrast
- **Multiple Rounds**: Continuous gameplay with restart capability

## 🔧 Hardware Requirements

### Components Used
- **1x Elegoo UNO R3** (Arduino UNO compatible)
- **1x LCD Display 16x2** (HD44780 compatible)
- **1x LED** (any color)
- **1x Push Button**
- **1x Potentiometer** (10kΩ recommended)
- **1x 220Ω Resistor** (for LED)
- **1x 10kΩ Resistor** (pull-down for button)
- **Jumper wires**
- **Breadboard**


## 🎮 How to Play

1. **Power On**: The game starts with a welcome message
2. **Get Ready**: Press the button when prompted to start a round
3. **Wait**: The screen shows "Wait..." - stay alert but don't press yet!
4. **React**: When the LED lights up and "PRESS NOW!" appears, hit the button as fast as possible
5. **Results**: Your reaction time is displayed in milliseconds
6. **Repeat**: Press the button to play another round

## 📊 Game Flow

```
Start Game
    ↓
Display Welcome Message
    ↓
Wait for Button Press
    ↓
Show "Get Ready..."
    ↓
Random Delay (2000-5000ms)
    ↓
Turn ON LED + "PRESS NOW!"
    ↓
Measure Reaction Time
    ↓
Display Results
    ↓
Wait for Next Round
```

## 📈 Possible Enhancements

- **High Score Tracking**: Store best reaction times in EEPROM
- **Multiple Difficulty Levels**: Varying wait times and visual cues
- **Sound Effects**: Add buzzer for audio feedback
- **Multi-Player Mode**: Take turns and compare scores
- **Statistics**: Track average reaction time over multiple rounds
- **False Start Detection**: Penalize early button presses

## 🛠️ Development Environment

- **Hardware**: Elegoo UNO R3 Starter Kit
- **IDE**: Arduino IDE 2.x
- **Libraries Used**: 
  - `LiquidCrystal.h` (built-in)
  - Standard Arduino libraries

## 📜 License
This project is open source and available under the MIT License.
