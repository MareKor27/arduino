#include <LiquidCrystal.h> 
LiquidCrystal lcd(2, 3, 4, 5, 6, 7); 
#define ANALOG_PIN A0
#define BRIGHTNESSCONTROL 11

int brightness = 100;
int change = 5;    
boolean direction = true;
double readValue = 0;

void setup() {

  lcd.begin(16, 2); 
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Arduino ON!");
  delay(1000);
  lcd.setCursor(0,0);
  lcd.print("Arduino Screen");
  lcd.setCursor(0,1);
  lcd.print("----<>----"); 
}

void loop()
{
  analogWrite(BRIGHTNESSCONTROL, brightness);    
  brightness += direction? change : -change; 
  if (brightness == 0 || brightness == 255) { 
    direction = !direction;
  }
  readValue = analogRead(ANALOG_PIN)*5.0/1024.0;     
  lcd.setCursor(0,1);
  lcd.print("----<"+String(readValue)+">----"); 
  delay(100); 
}