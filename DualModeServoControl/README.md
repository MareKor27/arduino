# Servo Control with Mode Switch (Potentiometer / Serial Input)

This Arduino project allows you to control a servo motor in two modes:

- **Automatic mode** – using a potentiometer (connected to analog pin A5)
- **Manual mode** – entering the angle via Serial Monitor

## Components Used

- Arduino board
- Servo motor (connected to pin 5)
- Push button (connected to pin 12)
- Potentiometer (connected to A5)
- USB for serial communication

## How It Works

- Press the button to switch between automatic and manual mode.
- In automatic mode, the servo angle follows the potentiometer value (0–180°).
- In manual mode, you are prompted to enter a value between 0 and 180 via Serial Monitor. The servo moves to that angle.
- The current angle is printed to the Serial Monitor in both modes.

## Notes

- The button uses internal pull-up (`INPUT_PULLUP`), so it should be connected to GND when pressed.
- Angle inputs outside the 0–180 range are rejected in manual mode.
