# 🌈 RGB LED and NeoPixel Strip Effects – Arduino Project

This Arduino project demonstrates how to control:

- **Two RGB LEDs** using PWM pins
- An **8-pixel NeoPixel strip** with color animation and fading effects

It also includes advanced visual effects based on the official **Adafruit NeoPixel library examples**.

---

## 🧰 Required Hardware

| Component               | Quantity  |
| ----------------------- | --------- |
| Arduino Uno / Nano      | 1         |
| Common Cathode RGB LED  | 2         |
| 220Ω resistors          | 6         |
| NeoPixel Strip (8 LEDs) | 1         |
| Breadboard & jumpers    | As needed |

---

## 🔌 Wiring

### RGB LED 1 (Common Cathode)

| Pin   | Arduino Pin |
| ----- | ----------- |
| Red   | D3          |
| Green | D5          |
| Blue  | D6          |
| GND   | GND         |

### RGB LED 2 (Common Cathode)

| Pin   | Arduino Pin |
| ----- | ----------- |
| Red   | D9          |
| Green | D10         |
| Blue  | D11         |
| GND   | GND         |

### NeoPixel Strip

| Strip Pin | Arduino Pin |
| --------- | ----------- |
| DIN       | A0          |
| +5V       | 5V          |
| GND       | GND         |

> ⚠️ Don't forget to add a **1000µF capacitor** across the +5V and GND near the strip, and a **300-500Ω resistor** on the data line to ensure stable performance.

---

## 📋 Code Features

### 🔸 Custom RGB + NeoPixel Control

- **RGB LEDs** fade in and out using `analogWrite()`, with color components reacting to a random value.
- **NeoPixel strip** lights up in sections:
  - First 2 LEDs = Red
  - Next 2 = Yellow
  - Next 2 = Cyan
  - Last 2 = Green

```cpp
analogWrite(RED_LED1, randomValue);
analogWrite(GREEN_LED1, fadeValue);
analogWrite(BLUE_LED1, 255 - fadeValue);
```

### 🔸 NeoPixel Library Example Effects

Includes:

- `colorWipe()` – Sequential color fill
- `theaterChase()` – Moving dotted marquee effect
- `rainbow()` – Flowing rainbow across the strip
- `theaterChaseRainbow()` – Marquee with shifting rainbow colors

---

## 💡 Tips for Best Results

- Set brightness using `strip.setBrightness(50);`
- Use a dedicated power supply if powering more than 8 LEDs
- Keep wiring short between Arduino and NeoPixels

---

## 📚 Libraries Used

Install via Library Manager:

```
Adafruit NeoPixel by Adafruit
```
