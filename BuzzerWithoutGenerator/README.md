# 🎵 Arduino Melody Player – "Sto lat" on a Buzzer

This Arduino project demonstrates how to play a melody (specifically, the Polish birthday song **"Sto lat"**) using a **passive buzzer** and the `tone()` function. It includes musical note definitions, melody timing, and playback functionality.

## 🧰 Required Components

- Arduino Uno / Nano / other compatible board
- Passive buzzer (connected to pin `A4`)
- Jumper wires
- Optional: push button to trigger playback manually

## 🔌 Wiring

| Component  | Arduino Pin | Description             |
| ---------- | ----------- | ----------------------- |
| Buzzer (+) | A4          | Signal pin (BUZZER_PIN) |
| Buzzer (–) | GND         | Ground                  |

> ⚠️ Make sure to use a **passive** buzzer (a two-pin buzzer without a built-in oscillator). Active buzzers will not work properly with `tone()`.

## 🎼 How It Works

1. **Note Definitions**: A large set of constants defines musical notes as frequencies in Hz.
2. **Melody Array**: The `melody[]` array stores the sequence of notes for the song.
3. **Note Durations**: The `noteDurations[]` array sets how long each note is played (in milliseconds).
4. The `playMelody()` function uses `tone()` and `noTone()` to play each note with a delay.
