# Arduino Alarm System – PIR & Magnetic Sensor with RGB LED

This project implements a simple home alarm system using an Arduino, a PIR motion sensor, a magnetic door sensor (reed switch), and RGB LEDs for status indication. The system uses **interrupts** to detect sensor events and change the state of the LED indicators accordingly.

## 🔧 Hardware Components

- Arduino Uno (or compatible)
- PIR motion sensor (connected to digital pin 2)
- Magnetic contact sensor (kontaktron) (connected to digital pin 3)
- RGB LED or three separate LEDs (Red – pin 10, Green – pin 11, Blue – pin 12)
- Optional: signal LED (pin 13)
- Resistors for LEDs
- Breadboard and jumper wires

## ⚙️ Pin Configuration

| Pin  | Function               |
| ---- | ---------------------- |
| `2`  | PIR sensor (motion)    |
| `3`  | Magnetic sensor (door) |
| `10` | Red LED (alarm on)     |
| `11` | Green LED (alarm off)  |
| `12` | Blue LED (unused here) |
| `13` | Signal LED (optional)  |

## 🧠 How It Works

- **Green LED ON** = system idle (no alarm).
- When motion ends (PIR goes LOW) or the door is opened (kontaktron triggers RISING edge), an interrupt is fired.
- Inside the interrupt, the **Red LED** is turned on and green is turned off — indicating an **alarm**.
- In the `loop()`, the flags are reset and green LED is re-enabled after a short delay.

> Note: Interrupts are used to ensure quick reaction to sensor events.

## 📝 Code Highlights

- Uses `attachInterrupt()` to detect:
  - `FALLING` edge for PIR (motion ends).
  - `RISING` edge for magnetic sensor (contact opens).
- `Serial.begin(9600)` is enabled for basic debugging via `Serial Monitor`.

## ⚠️ Notes

- Avoid using `Serial.println()` inside an interrupt in production. It's used here for basic debug info only.
- Make sure contacts are debounced if you're getting multiple false triggers.
- Do not connect sensors to pins 0 or 1 if using `Serial`.
