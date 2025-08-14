# Parking Sensor System

A smart parking assistance system using Arduino and ultrasonic sensor technology to help drivers park safely by detecting obstacles and providing real-time audio-visual feedback.

## 🎯 Project Overview

This parking sensor system mimics the functionality found in modern vehicles, providing distance measurements and alerts when approaching obstacles. The system uses an ultrasonic sensor to measure distances and provides feedback through LEDs and a buzzer with varying intensity based on proximity.

## ✨ Features

- **Real-time Distance Measurement**: Continuous monitoring using HC-SR04 ultrasonic sensor
- **Power Management**: LED keeps the system active to prevent powerbank hibernation
- **Audio Alerts**: Buzzer with three different sound patterns based on distance
- **Customizable Thresholds**: Adjustable distance ranges for different alert levels
- **Compact Design**: Easy to install and portable

## 🔧 Hardware Components

| Component | Quantity | Description |
|-----------|----------|-------------|
| Arduino Uno | 1 | Main microcontroller |
| HC-SR04 Ultrasonic Sensor | 1 | Distance measurement sensor |
| LED | 1 | System activity indicator (prevents powerbank hibernation) |
| Buzzer | 1 | Audio feedback |
| Resistor | 1 | Current limiting for LED (220Ω) |
| Breadboard | 1 | Circuit prototyping |
| Jumper Wires | Multiple | Connections |
| Powerbank | 1 | Portable power supply |

## ⚡ How It Works

1. **Distance Measurement**: The HC-SR04 sensor continuously measures the distance to the nearest obstacle
2. **Power Management**: The LED stays constantly on to keep the powerbank active (prevents 35-second hibernation)
3. **Audio Feedback System**: Based on distance thresholds:
   - **> 30cm**: No sound (Safe zone)
   - **< 30cm**: First sound pattern (Caution zone)
   - **< 20cm**: Second sound pattern (Warning zone)  
   - **< 10cm**: Third sound pattern (Danger zone)

## 🚀 Future Enhancements

- [ ] LCD display showing exact distance
- [ ] Multiple LED's for a better visual experience
- [ ] Multiple sound patterns for better differentiation
- [ ] Wireless connectivity (Bluetooth/WiFi)
- [ ] Multiple sensor array for corner detection
- [ ] Mobile app integration
- [ ] Weatherproof enclosure design

## 📝 Lessons Learned

- Powerbank hibernation can be prevented with constant LED activity
- Ultrasonic sensors work best with flat, perpendicular surfaces
- Three-tier audio system provides clear distance feedback
- Proper power management is crucial for portable projects

## 📄 License

This project is open source and available under the [MIT License](../LICENSE).

---

**Created by**: [Nasim Chaabani]     
**Last Updated**: [14/08/2025]