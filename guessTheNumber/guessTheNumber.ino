#define startGameButton 2
#define greenLed 13
#define yellowLed1 12
#define yellowLed2 11
#define redLed 10

const int AMPLITUDE = 50;
const int NUMBER_OF_ATTEMPTS = 3;
const int LED_BLINK_COUNT = 20;

int readValue = 0;
int repeatCounter = 0;
String receivedData = "";

void setupLeds() {
  pinMode(greenLed, OUTPUT);
  pinMode(yellowLed1, OUTPUT);
  pinMode(yellowLed2, OUTPUT);
  pinMode(redLed, OUTPUT);
  resetLeds();
}

void resetLeds() {
  digitalWrite(greenLed, LOW);
  digitalWrite(yellowLed1, LOW);
  digitalWrite(yellowLed2, LOW);
  digitalWrite(redLed, LOW);
}

void blinkLed(int pin, int times, int delayTime = 200) {
  for (int i = 0; i < times; i++) {
    digitalWrite(pin, HIGH);
    delay(delayTime);
    digitalWrite(pin, LOW);
    delay(delayTime);
  }
}

void updateLeds() {
  if (repeatCounter == 1) {
    digitalWrite(greenLed, LOW);
    digitalWrite(yellowLed1, HIGH);
  } else if (repeatCounter == 2) {
    digitalWrite(yellowLed1, LOW);
    digitalWrite(yellowLed2, HIGH);
  } else {
    resetLeds();
  }
}

void setup() {
  Serial.begin(9600);
  Serial.println("Witaj na Arduino!");
  
  pinMode(startGameButton, INPUT_PULLUP);
  setupLeds();
}

void loop() {
  Serial.println("Wylosuj liczbę i zatwierdź przyciskiem!");
  
  while (digitalRead(startGameButton) == HIGH) {
    readValue = analogRead(A5);
  }

  digitalWrite(greenLed, HIGH);
  digitalWrite(redLed, LOW);
  repeatCounter = 0;

  Serial.println("Podaj liczbę:");
  delay(300);

  while (repeatCounter < NUMBER_OF_ATTEMPTS) {
    if (Serial.available() > 0) {
      receivedData = Serial.readStringUntil('\n');
      int guessed = receivedData.toInt();

      Serial.println("Wybrałeś " + receivedData + "!");

      if (abs(guessed - readValue) < AMPLITUDE) {
        Serial.println("Wygrałeś! Liczba z potencjometru to: " + String(readValue));
        resetLeds();
        blinkLed(greenLed, LED_BLINK_COUNT);
        break;
      } else {
        Serial.println(guessed < readValue ? "Więcej!" : "Mniej!");
        repeatCounter++;
        if (repeatCounter != NUMBER_OF_ATTEMPTS) {
          Serial.println("Pudło: " + receivedData + " spróbuj jeszcze raz.");
        }
        updateLeds();
      }
    }
  }

  if (repeatCounter == NUMBER_OF_ATTEMPTS) {
    Serial.println("Niestety nie udało się! Liczba to: " + String(readValue));
    blinkLed(redLed, LED_BLINK_COUNT);
  }

  delay(5000);
}


