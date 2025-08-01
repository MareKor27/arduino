#include "SevSeg.h"
#include <OneWire.h>
#include <DallasTemperature.h>
#include <Adafruit_NeoPixel.h>
#include "DHT.h"

// Constants
#define DHT11_PIN 11
#define LM35_PIN A5
#define NUM_PIXELS 8
#define PIXEL_PIN A0

// Display and Sensor Setup
SevSeg sevenSegmentDisplay;
DHT dhtSensor;
OneWire oneWire(LM35_PIN);
DallasTemperature tempSensors(&oneWire);
Adafruit_NeoPixel ledBar = Adafruit_NeoPixel(NUM_PIXELS, PIXEL_PIN, NEO_GRB + NEO_KHZ800);

void setup() {
  // Setup 7-segment display
  byte numDigits = 2;
  byte digitPins[] = {10, 9}; // Control pins for each digit
  byte segmentPins[] = {7, 5, 2, 4, 3, 8, 6}; // Segment pins A to G
  bool resistorsOnSegments = true;
  byte hardwareConfig = N_TRANSISTORS;

  sevenSegmentDisplay.begin(hardwareConfig, numDigits, digitPins, segmentPins, resistorsOnSegments);

  // Serial communication
  Serial.begin(9600);

  // Initialize sensors
  dhtSensor.setup(DHT11_PIN);
  tempSensors.begin();
  ledBar.begin();
  ledBar.setBrightness(10); // Lower brightness for power saving and eye comfort
}

void loop() {
  // Read humidity and temperature from DHT11
  int humidity = dhtSensor.getHumidity();
  int dhtTemperature = dhtSensor.getTemperature();

  Serial.print(humidity);
  Serial.print("%RH | ");
  Serial.print(dhtTemperature);
  Serial.println("*C");

  // Read temperatures from DS18B20 sensors
  tempSensors.requestTemperatures();
  float temperature1 = tempSensors.getTempCByIndex(0);
  float temperature2 = tempSensors.getTempCByIndex(1);

  Serial.print("Temperature 1: ");
  Serial.print(temperature1);
  Serial.println("*C");

  Serial.print("Temperature 2: ");
  Serial.print(temperature2);
  Serial.println("*C");

  // Update LED bar with temperature 2
  updateTemperatureBar(temperature2);

  // Update 7-segment display with humidity value
  sevenSegmentDisplay.setNumber(humidity, 2);
  sevenSegmentDisplay.refreshDisplay();
}

// Function to map temperature to RGB LED bar
void updateTemperatureBar(int temperature) {
  // Clamp temperature to range [-40, 40]
  if (temperature > 40) {
    temperature = 40;
  } else if (temperature < -40) {
    temperature = -40;
  }

  ledBar.clear();

  if (temperature >= 0) {
    // Positive temperatures: Red LEDs
    int mappedTemp = map(temperature, 0, 40, 1, NUM_PIXELS);
    for (int i = 0; i < mappedTemp; i++) {
      ledBar.setPixelColor(i, ledBar.Color(255, 0, 0)); // Red
    }
  } else {
    // Negative temperatures: Blue LEDs
    int mappedTemp = map(temperature, -40, 0, 1, NUM_PIXELS);
    for (int i = NUM_PIXELS - 1; i >= mappedTemp; i--) {
      ledBar.setPixelColor(i, ledBar.Color(0, 0, 255)); // Blue
    }
  }

  ledBar.show();
}
