# 🔐 Arduino Alarm System

This is a simple security alarm system built using Arduino, a 4x4 keypad, PIR sensor, contact sensor (magnetic switch), NeoPixel LED strip, and a buzzer. The system monitors movement or door opening and activates an alarm when triggered.

> 💬 Komentarze w kodzie źródłowym pozostają w języku polskim, aby ułatwić zrozumienie projektu dla polskich użytkowników.

---

## 📦 Components Required

- Arduino Uno / Nano
- 4x4 Keypad
- PIR Motion Sensor
- Magnetic Contact Sensor (Reed switch)
- NeoPixel LED Strip (8 LEDs)
- Buzzer
- Jumper wires
- Breadboard
- Resistors (as needed)

---

## ⚙️ How It Works

The alarm system works as a **finite state machine** with the following states:

1. **Standby** – System is idle and ready to be armed (`A` key).
2. **Arming** – LEDs animate, alarm is being armed.
3. **Monitoring** – Motion/contact is monitored.
4. **Disarming** – If the contact sensor is triggered, user must enter a 4-digit PIN.
5. **Alarm** – If the wrong PIN is entered or movement is detected, an audible and visual alarm is triggered.

Use key `B` during alarm to reset back to standby.

---

## 🔑 Default PIN Code

```
1234
```

You can change it in the following line of the code:

```cpp
char pinCode[] = {'1','2','3','4'};
```

---

## ⌨️ Keypad Controls

| Key | Function           |
| --- | ------------------ |
| A   | Arm the system     |
| B   | Stop alarm / Reset |
| 0-9 | Enter PIN code     |

---

## ⭮️ System States Summary

| State      | Description                                    |
| ---------- | ---------------------------------------------- |
| Standby    | Green LED, waits for arming                    |
| Arming     | Blue to red LED animation with buzzer tones    |
| Monitoring | Blinking red LED, reads PIR and contact sensor |
| Disarming  | User must enter correct PIN                    |
| Alarm      | Flashing LEDs and buzzer sound; reset with `B` |

---

## 🚀 Future Improvements (Suggestions)

- Allow PIN change via keypad
- Add LCD display to show status
- Log events to SD card or serial monitor
- Add remote arm/disarm functionality via Bluetooth or Wi-Fi

---

## Installation

1. Connect all components according to pin assignments in the code.
2. Install required libraries:

   - `Keypad`
   - `Adafruit_NeoPixel`

3. Upload the code to your Arduino board via the Arduino IDE.
4. Open Serial Monitor (9600 baud) for debug output.

---
