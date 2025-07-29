#include <Keypad.h> //biblioteka od klawiatury
#include <Adafruit_NeoPixel.h> //biblioteka od linijki LED

#define BUZZER 11
#define CONTACT_SENSOR 10
#define PIR_SENSOR 12
#define LED_PIN A0

const byte ROWS = 4; // ile wierszy
const byte COLS = 4; // ile kolumn
byte rowPins[ROWS] = {6, 7, 8, 9}; //piny wierszy
byte colPins[COLS] = {5, 4, 3, 2}; //piny kolumn

char keys[ROWS][COLS] = { //mapowanie klawiatury
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};

char pinCode[] = {'1','2','3','4'};
const byte pinLength = 4;
int elapsedTime = 0;
bool hasError = false;

Keypad keypadDevice = Keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS); //inicjalizacja klawiatury
Adafruit_NeoPixel ledStrip = Adafruit_NeoPixel(8, LED_PIN, NEO_GRB + NEO_KHZ800); //konfiguracja linijki LED
volatile int alarmState = 1;

void turnOffLEDs() {
  for (int i = 0; i < 8; i++) {
    ledStrip.setPixelColor(i, ledStrip.Color(0, 0, 0)); //Dioda nr i wyłączona    
  }
  ledStrip.show();
}

void setup() {
  Serial.begin(9600);
  pinMode(BUZZER, OUTPUT);
  pinMode(CONTACT_SENSOR, INPUT_PULLUP);
  pinMode(PIR_SENSOR, INPUT_PULLUP);

  ledStrip.begin(); //inicjalizacja linijki
  ledStrip.show();
}
  
void loop() {
  char keyPressed = 0;

  switch (alarmState) { //Wykonywanie akcji odpowiednich dla danego stanu
    case 1:
      //Czuwanie
      ledStrip.setPixelColor(0, ledStrip.Color(0, 15, 0)); //Dioda nr 1 świeci na zielono
      ledStrip.show();
      keyPressed = keypadDevice.getKey();
      hasError = false;

      if (keyPressed == 'A') { //Czy uzbroić alarm?
        for (int i = 1; i < 8; i++) {
          ledStrip.setPixelColor(i, ledStrip.Color(0, 0, 15)); //Dioda nr i świeci na niebiesko
          ledStrip.show();
          delay(710);
        }

        for (int i = 1; i < 8; i++) {
          ledStrip.setPixelColor(i, ledStrip.Color(15, 0, 0)); //Dioda nr i świeci na czerwono
          ledStrip.show();
          delay(310);
          tone(BUZZER, 5000);
          delay(200);
          noTone(BUZZER);
        }

        tone(BUZZER, 1300);
        delay(200);
        tone(BUZZER, 6300);
        delay(200);
        noTone(BUZZER);
        turnOffLEDs();
        alarmState = 2;
      }
    break;
    
    case 2:
      //Monitorowanie
      ledStrip.setPixelColor(7, ledStrip.Color(15, 0, 0)); //Dioda nr 8 świeci na czerwono
      ledStrip.show();
      delay(50);
      ledStrip.setPixelColor(7, ledStrip.Color(0, 0, 0)); //Dioda nr 8 wyłączona
      ledStrip.show();
      delay(150);

      Serial.println("PIR:");
      Serial.println(digitalRead(PIR_SENSOR));
      Serial.println("CONTACT_SENSOR:");  
      Serial.println(digitalRead(CONTACT_SENSOR));

      if (digitalRead(PIR_SENSOR) == HIGH) {
        alarmState = 4; //Natychmiast uruchamiamy alarm
      } else if (digitalRead(CONTACT_SENSOR) == HIGH) {
        alarmState = 3; //Szansa na rozbrojenie
        elapsedTime = 0; //Zerowanie zmiennej
        tone(BUZZER, 5000);
        delay(100);
        noTone(BUZZER);
      }
    break;
    
    case 3:
      //Rozbrajanie
      for (int i = 0; i < pinLength; i++) {
        do {
          keyPressed = keypadDevice.getKey();
          delay(100);
          elapsedTime++;
          Serial.println(elapsedTime); 
          if (elapsedTime >= 500) {
            hasError = true;
            break;
          }
        } while (keyPressed == NO_KEY);

        if (keyPressed != pinCode[i]) {
          hasError = true;
          break;
        } else {
          tone(BUZZER, 1000);
          delay(200);
          noTone(BUZZER);
        }
      }

      if (hasError) {
        alarmState = 4; // zły PIN – uruchom alarm
      } else {
        alarmState = 1; // poprawny PIN – wróć do stanu czuwania
        delay(1000);
        tone(BUZZER, 200);
        delay(150);
        tone(BUZZER, 600);
        delay(150);
        tone(BUZZER, 1000);
        delay(150);
        noTone(BUZZER);
      }
    break;
    
    case 4:
      //Alarm
      for (int i = 0; i < 8; i++) {
        ledStrip.setPixelColor(i, ledStrip.Color(255, 0, 0)); //Dioda nr i świeci na czerwono 
      }
      ledStrip.show();
      tone(BUZZER, 4300);
      delay(100);

      for (int i = 0; i < 8; i++) {
        ledStrip.setPixelColor(i, ledStrip.Color(0, 0, 255)); //Dioda nr i świeci na niebiesko 
      }
      ledStrip.show();
      tone(BUZZER, 3500);
      delay(100);

      keyPressed = keypadDevice.getKey();
      if (keyPressed == 'B') {
        alarmState = 1;
        ledStrip.clear();
        noTone(BUZZER);
      }
    break;
  }
}
