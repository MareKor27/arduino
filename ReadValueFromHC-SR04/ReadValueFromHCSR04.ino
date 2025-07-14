// void blinkingLed(int PIN,int repeat = 2,int blinkTime = 500){
//   pinMode(PIN, OUTPUT);
//   for(int i= 0;i<repeat;i++){
//     digitalWrite(PIN, HIGH);
//     delay(blinkTime);
//     digitalWrite(PIN, LOW);
//     delay(blinkTime);
//   }
// }

// void lighteningLed(int PIN,int repeat = 2, int fullFillmewnt = 255){
//   pinMode(PIN, OUTPUT);
//   for(int i=0; i< repeat;i++){
//     for(int j= 0;j<fullFillmewnt;j++){
//     analogWrite(PIN, j);
//     delay(50);
//   }
//   }
// }

#define trigPin 12
#define echoPin 11

int measureDistance() {
  long time, distance;
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  time = pulseIn(echoPin, HIGH);
  distance = time / 58;
  Serial.println(distance);
  return distance;
}

void range(int a, int b) {
  int howFarAway = measureDistance();
  if ((howFarAway > a) && (howFarAway < b)) {
      digitalWrite(2, HIGH); //Włączamy buzzer
  } else {
      digitalWrite(2, LOW); //Wyłączamy buzzer, gdy obiekt poza zakresem
  }
}

void setup() {
  Serial.begin (9600);
  pinMode(trigPin, OUTPUT); //Pin, do którego podłączymy trig jako wyjście
  pinMode(echoPin, INPUT); //a echo, jako wejście
  pinMode(2, OUTPUT); //Wyjście dla buzzera
}

void loop() {
  delay(500);
  range(270, 278);
}


