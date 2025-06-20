#define greenRightLed 12
#define yellowRightLed 11
#define blueLed 10
#define yellowLeftLed 9
#define greenLeftLed 8

const int sensorLeftPin = A5;
const int sensorRightPin = A4;

int leftValue = 0;
int rightValue = 0;
int diff = 0;

void setLeds(int gRight, int yRight, int blue, int yLeft, int gLeft) {
  digitalWrite(greenRightLed, gRight);
  digitalWrite(yellowRightLed, yRight);
  digitalWrite(blueLed, blue);
  digitalWrite(yellowLeftLed, yLeft);
  digitalWrite(greenLeftLed, gLeft);
}

void setup() {
  Serial.begin(9600);
  Serial.println("Arduino ON!");

  pinMode(greenRightLed, OUTPUT);
  pinMode(yellowRightLed, OUTPUT);
  pinMode(blueLed, OUTPUT);
  pinMode(yellowLeftLed, OUTPUT);
  pinMode(greenLeftLed, OUTPUT);

  // Test all LEDs
  setLeds(HIGH, HIGH, HIGH, HIGH, HIGH);
  delay(500);
  setLeds(LOW, LOW, LOW, LOW, LOW);
}

void loop() {
  leftValue = analogRead(sensorLeftPin);
  rightValue = analogRead(sensorRightPin);
  diff = leftValue - rightValue;

  Serial.print("L: "+String(leftValue)+" ("+String(diff)+") "+String(rightValue)+":R");

  // Interpret light direction
  if (diff > 200) {
    setLeds(LOW, LOW, LOW, LOW, HIGH); // Mocno z lewej
  } else if (diff > 100) {
    setLeds(LOW, LOW, LOW, HIGH, LOW); // Lekko z lewej
  } else if (abs(diff) <= 100) {
    setLeds(LOW, LOW, HIGH, LOW, LOW); // Środek
  } else if (diff < -100 && diff > -200) {
    setLeds(LOW, HIGH, LOW, LOW, LOW); // Lekko z prawej
  } else if (diff < -200) {
    setLeds(HIGH, LOW, LOW, LOW, LOW); // Mocno z prawej
  }

  delay(200);
}

