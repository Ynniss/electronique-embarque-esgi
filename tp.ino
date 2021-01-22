#include "DHT.h"
#define PIN 4

#include <Wire.h>
#include "rgb_lcd.h"

rgb_lcd lcd;

const int colorR = 255;
const int colorG = 0;
const int colorB = 0;

DHT dht(PIN, DHT11);

void setup() {
  //Serial.begin(9600);
  dht.begin();
  Serial.println("Commencement du programme");
}

void afficherTemerature_Humidite(){
  float humidity = dht.readHumidity();
  float temperature = dht.readTemperature();

    //afficher sur la console
  Serial.print("Humidité : ");
  Serial.print(humidity);
  Serial.print("Temperature : ");
  Serial.print(temperature);
  Serial.println();

    //afficher sur l'ecran
  lcd.setCursor(0, 0);
  lcd.print("H: ");
  lcd.print(humidity);
  lcd.setCursor(0, 1);
  lcd.print("T: ");
  lcd.print(temperature);
}

void loop() {
  afficherTemerature_Humidite();
  delay(1000);
}
