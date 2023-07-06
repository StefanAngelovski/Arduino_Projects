#include <Arduino_ST7789_Fast.h>
#include "DHT.h"
#define Type DHT11
int prevT=0, prevH=0;
int humidity, temperature;
int sensePin = 2;
DHT HT(sensePin, Type);
Arduino_ST7789 lcd = Arduino_ST7789(7, 8);
void setup() {
  lcd.init(240, 240); //initialize screen resolution
  lcd.fillScreen(BLACK); 
  lcd.setTextColor(WHITE);
  lcd.setTextSize(3);

  HT.begin();
}

void loop() {
  temperature = HT.readTemperature();
  humidity = HT.readHumidity();
  if(prevT!=temperature || prevH!=humidity) lcd.clearScreen();
  lcd.setCursor(0, 0);
  lcd.println("Temperature: ");
  lcd.println(temperature); //Temperature
  lcd.println("Humidity: ");
  lcd.println(humidity); //Humidity
  prevT = temperature;
  prevH = humidity;
  delay(1000);
}
