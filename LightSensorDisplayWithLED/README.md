# Light Sensor Display with LED Pulse

This Arduino project displays ambient light levels measured using a photoresistor on a 16x2 LCD. Simultaneously, an LED connected to PWM pin 11 pulses smoothly to create a visual effect. The LED brightness is animated independently and not related to the sensor readings.

## Features

- 📟 Real-time display of light level (in volts) using a photoresistor.
- 💡 LED with smooth pulsing effect using PWM.
- 🎛️ Potentiometer for LCD contrast adjustment.
- 🔌 Beginner-friendly circuit with minimal components.

## Components Required

| Component          | Quantity  | Notes                                 |
| ------------------ | --------- | ------------------------------------- |
| Arduino UNO/Nano   | 1         | Any compatible Arduino board          |
| Photoresistor      | 1         | 5kΩ–10kΩ light-dependent resistor     |
| Potentiometer      | 1         | 5kΩ, used to adjust LCD contrast      |
| Resistor           | 1         | 1kΩ, used in voltage divider with LDR |
| LED                | 1         | For visual pulsing effect             |
| 16x2 LCD Display   | 1         | Based on HD44780 driver               |
| Breadboard + wires | As needed | For prototyping and connections       |

## Circuit Connections

### LCD (using LiquidCrystal library)

| LCD Pin | Arduino Pin |
| ------- | ----------- |
| RS      | 2           |
| E       | 3           |
| D4      | 4           |
| D5      | 5           |
| D6      | 6           |
| D7      | 7           |

## Code Overview

- `analogRead(A0)` reads the voltage from the photoresistor circuit.
- Voltage is converted to a readable 0–5V value and displayed on LCD.
- `analogWrite(11, brightness)` creates a fade-in/fade-out LED effect.

## LCD Output Example

Arduino Screen
----<2.43>----
