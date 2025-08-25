#include <LiquidCrystal.h> //Dołączenie bilbioteki
#include "DHT.h"

#define DHT11_PIN 8
#define sensor_A0 A0    // podłączenie od A0 na czujniku do A0 na Arduino
#define sensor_PIN_D0 9 // podłączenie od D0 na czujniku do pinu 9 na Arduino

DHT dht;
LiquidCrystal lcd(2, 3, 4, 5, 6, 7); //Informacja o podłączeniu nowego wyświetlacza

int wartosc_A0;        // zmienna dla wartości A0

void setup() {
  pinMode(sensor_PIN_D0, INPUT);
  //=====================
  dht.setup(DHT11_PIN);
  lcd.begin(16, 2); //Deklaracja typu
  lcd.setCursor(0, 0); //Ustawienie kursora
  lcd.print("Mala stacja"); //Wyświetlenie tekstu
  lcd.setCursor(0, 1); //Ustawienie kursora
  lcd.print("Pogodowa!"); //Wyświetlenie tekstu
  delay(1000);
}
void loop() {
  lcd.clear();
  //Pobranie informacji o wilgotnosci
  int wilgotnosc = dht.getHumidity();
  lcd.setCursor(0, 0);
  lcd.print("W:" + String(wilgotnosc)+"%RH"); //Wyświetlenie tekstu
  
  //Pobranie informacji o temperaturze
  int temperatura = dht.getTemperature();
  lcd.setCursor(0, 1);
  lcd.print("T:" + String(temperatura)+"*C"); //Wyświetlenie tekstu

  wartosc_A0 = analogRead(sensor_A0);      // pobranie wartości z A0
  lcd.setCursor(8, 0);
  lcd.print("AW:" + String(wartosc_A0)); //Wyświetlenie tekstu

  delay(1000); //Odczekanie wymaganego czasu
}

