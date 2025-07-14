#define LED_R 10
#define LED_G 11
#define LED_B 12
#define LED_SYG 13

#define KONTAKTRON 3
#define PIR 2

bool triggerAlarmMOVE = false; // flaga sterująca alarmem
bool triggerAlarmKONTRAKTOR = false; // flaga sterująca alarmem

void setup() {
  Serial.begin(9600);
  pinMode(LED_R, OUTPUT);
  pinMode(LED_G, OUTPUT);
  pinMode(LED_B, OUTPUT);
  pinMode(LED_SYG, OUTPUT);

  pinMode(KONTAKTRON, INPUT_PULLUP);
  pinMode(PIR, INPUT);

  // Dioda domyślnie zielona (brak alarmu)
  digitalWrite(LED_R, LOW);
  digitalWrite(LED_G, HIGH);
  digitalWrite(LED_B, LOW);

  attachInterrupt(digitalPinToInterrupt(PIR), pirFallingMOVE, FALLING); 
  attachInterrupt(digitalPinToInterrupt(KONTAKTRON), pirFallingKONTRAKTOR, RISING); 
}

void loop() {

  delay(500);
  // Jeśli nastąpiło zakończenie ruchu – uruchom alarm
  if (triggerAlarmMOVE || triggerAlarmKONTRAKTOR) {
    digitalWrite(LED_R, LOW);  // Czerwona = alarm
    digitalWrite(LED_G, HIGH);
    triggerAlarmKONTRAKTOR = false; // Resetujemy flagę
    triggerAlarmMOVE = false; // Resetujemy flagę
  }
  
}

// Funkcja przerwania – gdy PIR przejdzie na LOW (czyli koniec ruchu)
void pirFallingMOVE() {
  digitalWrite(LED_R, HIGH);  // Czerwona = alarm
  digitalWrite(LED_G, LOW);
  triggerAlarmMOVE = true;
  Serial.println("triggerAlarmMOVE");
}
void pirFallingKONTRAKTOR() {
  digitalWrite(LED_R, HIGH);  // Czerwona = alarm
  digitalWrite(LED_G, LOW);
  triggerAlarmKONTRAKTOR = true;
  Serial.println("triggerAlarmKONTRAKTOR");
}
