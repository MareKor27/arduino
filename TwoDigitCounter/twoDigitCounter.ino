// Segment pin definitions for 7-segment display
#define SEG_C 2
#define SEG_E 3
#define SEG_D 4
#define SEG_B 5
#define SEG_G 6
#define SEG_A 7
#define SEG_F 8

// Display select pins for multiplexing (2-digit display)
#define DISP_1 9  // Left digit (tens)
#define DISP_2 10 // Right digit (ones)

// Button pins
#define BTN_PLUS 11
#define BTN_MINUS 12

int number = 0; // Counter value

void setup() {
  // Set segment pins as outputs
  pinMode(SEG_A, OUTPUT);
  pinMode(SEG_B, OUTPUT);
  pinMode(SEG_C, OUTPUT);
  pinMode(SEG_D, OUTPUT);
  pinMode(SEG_E, OUTPUT);
  pinMode(SEG_F, OUTPUT);
  pinMode(SEG_G, OUTPUT);

  // Set display control pins as outputs
  pinMode(DISP_1, OUTPUT);
  pinMode(DISP_2, OUTPUT);

  // Set button pins as inputs with pull-up resistors
  pinMode(BTN_PLUS, INPUT_PULLUP);
  pinMode(BTN_MINUS, INPUT_PULLUP);

  Serial.begin(9600);
}

void loop() {
  // Button handling
  if (digitalRead(BTN_PLUS) == LOW) {
    number++;
    if (number > 99) number = 99;
    Serial.println("PLUS");
    delay(300); // Debounce delay
  }

  if (digitalRead(BTN_MINUS) == LOW) {
    number--;
    if (number < 0) number = 0;
    Serial.println("MINUS");
    delay(300); // Debounce delay
  }

  // Display multiplexing
  for (int i = 0; i < 20; i++) {  // Rapid switching between digits
    int tens = number / 10;
    int ones = number % 10;

    digitalWrite(DISP_2, HIGH);    // Turn on right digit
    digitalWrite(DISP_1, LOW);     // Turn off left digit
    displayDigit(tens);
    delay(5);

    digitalWrite(DISP_2, LOW);     // Turn off right digit
    digitalWrite(DISP_1, HIGH);    // Turn on left digit
    displayDigit(ones);
    delay(5);
  }
}

// Function to display a digit on 7-segment
void displayDigit(int digit) {
  switch (digit) {
    case 0:
      digitalWrite(SEG_A, HIGH); digitalWrite(SEG_B, HIGH); digitalWrite(SEG_C, HIGH);
      digitalWrite(SEG_D, HIGH); digitalWrite(SEG_E, HIGH); digitalWrite(SEG_F, HIGH);
      digitalWrite(SEG_G, LOW); break;
    case 1:
      digitalWrite(SEG_A, LOW); digitalWrite(SEG_B, HIGH); digitalWrite(SEG_C, HIGH);
      digitalWrite(SEG_D, LOW); digitalWrite(SEG_E, LOW); digitalWrite(SEG_F, LOW);
      digitalWrite(SEG_G, LOW); break;
    case 2:
      digitalWrite(SEG_A, HIGH); digitalWrite(SEG_B, HIGH); digitalWrite(SEG_C, LOW);
      digitalWrite(SEG_D, HIGH); digitalWrite(SEG_E, HIGH); digitalWrite(SEG_F, LOW);
      digitalWrite(SEG_G, HIGH); break;
    case 3:
      digitalWrite(SEG_A, HIGH); digitalWrite(SEG_B, HIGH); digitalWrite(SEG_C, HIGH);
      digitalWrite(SEG_D, HIGH); digitalWrite(SEG_E, LOW); digitalWrite(SEG_F, LOW);
      digitalWrite(SEG_G, HIGH); break;
    case 4:
      digitalWrite(SEG_A, LOW); digitalWrite(SEG_B, HIGH); digitalWrite(SEG_C, HIGH);
      digitalWrite(SEG_D, LOW); digitalWrite(SEG_E, LOW); digitalWrite(SEG_F, HIGH);
      digitalWrite(SEG_G, HIGH); break;
    case 5:
      digitalWrite(SEG_A, HIGH); digitalWrite(SEG_B, LOW); digitalWrite(SEG_C, HIGH);
      digitalWrite(SEG_D, HIGH); digitalWrite(SEG_E, LOW); digitalWrite(SEG_F, HIGH);
      digitalWrite(SEG_G, HIGH); break;
    case 6:
      digitalWrite(SEG_A, HIGH); digitalWrite(SEG_B, LOW); digitalWrite(SEG_C, HIGH);
      digitalWrite(SEG_D, HIGH); digitalWrite(SEG_E, HIGH); digitalWrite(SEG_F, HIGH);
      digitalWrite(SEG_G, HIGH); break;
    case 7:
      digitalWrite(SEG_A, HIGH); digitalWrite(SEG_B, HIGH); digitalWrite(SEG_C, HIGH);
      digitalWrite(SEG_D, LOW); digitalWrite(SEG_E, LOW); digitalWrite(SEG_F, LOW);
      digitalWrite(SEG_G, LOW); break;
    case 8:
      digitalWrite(SEG_A, HIGH); digitalWrite(SEG_B, HIGH); digitalWrite(SEG_C, HIGH);
      digitalWrite(SEG_D, HIGH); digitalWrite(SEG_E, HIGH); digitalWrite(SEG_F, HIGH);
      digitalWrite(SEG_G, HIGH); break;
    case 9:
      digitalWrite(SEG_A, HIGH); digitalWrite(SEG_B, HIGH); digitalWrite(SEG_C, HIGH);
      digitalWrite(SEG_D, HIGH); digitalWrite(SEG_E, LOW); digitalWrite(SEG_F, HIGH);
      digitalWrite(SEG_G, HIGH); break;
  }
}
