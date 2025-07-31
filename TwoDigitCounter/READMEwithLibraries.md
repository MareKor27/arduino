# 2-Digit 7-Segment Display with Potentiometer Input (Arduino)

This project reads an **analog input** (e.g., from a **potentiometer or photoresistor**) and displays the scaled value (0–99) on a **2-digit 7-segment display** using the `SevSeg` Arduino library.

## 📦 Components

- **1x Arduino UNO (or compatible)**
- **1x 10kΩ potentiometer** (or photoresistor + fixed resistor as voltage divider)
- **1x 2-digit 7-segment display** (common cathode)
- **7x 220–470Ω resistors** (for segments)
- Breadboard and jumper wires

## 🔌 Wiring

### Segment Pins

Connect each segment (A-G) of both digits to Arduino pins:

| Segment | Arduino Pin |
| ------- | ----------- |
| A       | 7           |
| B       | 5           |
| C       | 2           |
| D       | 4           |
| E       | 3           |
| F       | 8           |
| G       | 6           |

### Digit Control

- Digit 1 (left) → Pin **10**
- Digit 2 (right) → Pin **9**

Use **NPN transistors (e.g., BC547)** if needed for digit switching, or drive common cathode pins directly if within current limits.

### Potentiometer

- Connect middle pin of potentiometer to **A0**
- Side pins to **5V** and **GND**

## ⚙️ Functionality

- Reads analog voltage from **A0**
- Scales value from `0–1023` → `0–99`
- Continuously displays the scaled value
- Uses **multiplexing** internally via the `SevSeg` library

## 💻 Arduino Code

The code uses the [SevSeg library](https://github.com/DeanIsMe/SevSeg) to handle digit multiplexing and segment control. It calls `setNumber()` to update the value, and `refreshDisplay()` in every loop to keep the display on.

### Key Functions:

- `analogRead(A0)` — reads analog voltage
- `map(value, 0, 1023, 0, 99)` — rescales the range
- `sevseg.setNumber()` — sets the number to show
- `sevseg.refreshDisplay()` — must be called repeatedly
