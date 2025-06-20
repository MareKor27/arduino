# 🎮 Arduino Number Guessing Game

This project is a simple and interactive **number guessing game** built using an **Arduino Uno**, a **5kΩ potentiometer**, **LED indicators**, and the **Serial Monitor** for user input.

## 🧠 How It Works

1. The game starts when the user **presses and holds** the start button.
2. While holding the button, the Arduino reads the **analog value** from the potentiometer (A5) and stores it as the **secret number**.
3. After releasing the button, the player has **three attempts** to guess the number via the **Serial Monitor**.
4. The Arduino gives feedback after each guess:
   - If the number is **too low** or **too high**
   - Whether the guess is **correct** (within ±50)
   - How many attempts are left
5. Visual feedback is provided with **LEDs**:
   - ✅ Green LED turns on at the start
   - 🟡 Yellow LEDs turn on after 1st and 2nd failed attempt
   - ❌ Red LED blinks if the player fails all three attempts
   - 🎉 Green LED blinks rapidly if the player guesses correctly

## 💡 Hardware Required

- 1x Arduino Uno (or compatible)
- 1x 5kΩ potentiometer (connected to A5)
- 1x push button (connected to pin 2, using internal pull-up)
- 1x green LED (pin 13)
- 2x yellow LEDs (pins 12 and 11)
- 1x red LED (pin 10)
- 4x 330Ω resistors (for LEDs)
- Jumper wires
- Breadboard
