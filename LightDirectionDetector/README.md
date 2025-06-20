# 🔦 Light Direction Detector (Arduino Uno)

This Arduino project uses **two photoresistors (LDRs)** to detect the direction of the strongest light source. The result is displayed using **five LEDs** to show whether the light is coming from the left, right, or center.

## 🧠 How It Works

- Two LDRs are placed on opposite sides of a breadboard.
- Their analog values are read from `A5` (left) and `A4` (right).
- The difference between them (`diff`) is calculated.
- Based on this value, one of five LEDs is lit up to indicate direction:

| Direction         | LED Lit                   |
| ----------------- | ------------------------- |
| Far Left          | `greenLeftLed` (pin 8)    |
| Slightly Left     | `yellowLeftLed` (pin 9)   |
| Center (balanced) | `blueLed` (pin 10)        |
| Slightly Right    | `yellowRightLed` (pin 11) |
| Far Right         | `greenRightLed` (pin 12)  |

The LEDs give a clear visual indication of light direction, allowing for gesture detection or light-following behaviors.

## 🧰 Hardware Used

- Arduino Uno R3
- 2x Photoresistors (LDR)
- 5x LEDs (Green, Yellow, Blue)
- 5x 330Ω resistors
- Breadboard + jumper wires

## 📦 Code Summary

- `analogRead()` is used to read both LDR values.
- A helper function `setLeds(...)` controls which LED is turned on.
- The program compares values and displays results every 200ms via serial and LEDs.
