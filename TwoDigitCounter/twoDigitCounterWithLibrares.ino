#include "SevSeg.h"
SevSeg sevseg; // Create a seven-segment display object

void setup() {
  byte numDigits = 2;   
  byte digitPins[] = {10, 9}; // Control pins for each digit
  byte segmentPins[] = {7, 5, 2, 4, 3, 8, 6}; // Pins for segments A to G

  bool resistorsOnSegments = true; // true if current-limiting resistors are on segment lines
  byte hardwareConfig = N_TRANSISTORS; // Use NPN transistor switching (common cathode)

  sevseg.begin(hardwareConfig, numDigits, digitPins, segmentPins, resistorsOnSegments);
}

void loop() {
  int sensorValue = analogRead(A0); // Read value from the potentiometer
  sensorValue = map(sensorValue, 0, 1023, 0, 99); // Scale to 0–99 range

  sevseg.setNumber(sensorValue, 2); // Display the number with 2 digits
  sevseg.refreshDisplay();         // Must be called repeatedly
}
