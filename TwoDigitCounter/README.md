# Two-Digit 7-Segment Counter with Multiplexing (Arduino)

This project implements a simple two-digit up/down counter using an Arduino, two 7-segment displays, and multiplexing. The segments are shared, and digit control is managed using **BC547 NPN transistors**. Button inputs allow the user to increment or decrement the displayed number.

## 🔧 Hardware Components

- **1x Arduino UNO or compatible**
- **2x LDD040AUE-101A** 7-segment common cathode displays
- **2x BC547** NPN transistors (for digit switching)
- **2x 10kΩ resistors** (base pull-down for transistors)
- **2x 1kΩ resistors** (current limiting for transistor base)
- **7x 220Ω–470Ω resistors** (current limiting for segment lines)
- **2x Push buttons** (for increment and decrement)
- Breadboard and jumper wires

## ⚙️ Functionality

- The code displays a two-digit number from 00 to 99.
- Button `PLUS` increments the number.
- Button `MINUS` decrements the number.
- Numbers are displayed using **multiplexing** (each digit lights up alternately).

## 🧠 How It Works

- **Multiplexing** is used to control both digits using shared segment lines (`SEG_A` to `SEG_G`) and separate digit control lines (`DISP_1`, `DISP_2`).
- **BC547 transistors** are used to switch the common cathode of each 7-segment display. Their bases are connected to Arduino through **1kΩ** resistors, and pull-down **10kΩ** resistors are connected to ground.
- Only one digit is turned on at a time, switching rapidly (every ~5ms), which creates the illusion of both digits being lit simultaneously.

## 🪛 Wiring Overview

### Segment Pins

- Connect segments A-G of both displays together and to Arduino digital pins via **220Ω–470Ω resistors**.

### Digit Control

- Common cathode of **Digit 1 (Left)** → Collector of **BC547 #1**
- Common cathode of **Digit 2 (Right)** → Collector of **BC547 #2**
- Emitter of both transistors → GND
- Base of each transistor:
  - Connected to Arduino pin (e.g., pin 9/10)
  - Via **1kΩ resistor**
  - With **10kΩ pull-down resistor** to GND

### Buttons

- Connected to Arduino with `INPUT_PULLUP` enabled.
- One side to pin (e.g., 11 for PLUS, 12 for MINUS), the other to GND.

## 💾 Arduino Pin Mapping

| Arduino Pin | Function        |
| ----------- | --------------- |
| 2–8         | Segment A–G     |
| 9           | Digit 1 control |
| 10          | Digit 2 control |
| 11          | PLUS button     |
| 12          | MINUS button    |
