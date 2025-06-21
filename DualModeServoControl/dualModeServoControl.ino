#include <Servo.h> //Biblioteka odpowiedzialna za serwa
  
#define BUTTON_PIN 12
#define SERVO_PIN 5
#define ANALOG_PIN A5

Servo servo;
bool manualMode = false;
String input = "";

void setup() {
  Serial.begin(9600);
  Serial.println("Arduino! ON");

  servo.attach(SERVO_PIN);
  pinMode(BUTTON_PIN, INPUT_PULLUP);
}

void loop() {
  static bool lastButtonState = HIGH;
  bool currentButtonState = digitalRead(BUTTON_PIN);

  // Wykrycie naciśnięcia (zbocze opadające)
  if (lastButtonState == HIGH && currentButtonState == LOW) {
    manualMode = !manualMode;
    delay(250);
  }
  lastButtonState = currentButtonState;

  if (!manualMode) {
    int analogValue = analogRead(ANALOG_PIN);
    int angle = map(analogValue, 0, 1023, 0, 180);
    servo.write(angle);
    Serial.println(angle);
    delay(250);
  } else {
    Serial.println("Wpisz kat 0-180:");
    while (!Serial.available()) {}
    if (Serial.available()) {
      input = Serial.readStringUntil('\n');
      int angle = input.toInt();
      if (angle >= 0 && angle <= 180) {
        servo.write(angle);
         Serial.println("Przesunięto do: " + String(angle) + " stopni!");
      } else {
        Serial.println("Błędny kąt");
      }
    }
    delay(850);
  }

 
}
