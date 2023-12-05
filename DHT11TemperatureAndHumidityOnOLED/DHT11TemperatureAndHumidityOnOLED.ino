#include <Arduino_ST7789_Fast.h>
#include <DHT.h> 
#define Type DHT11
int sensePin = 2;
DHT HT(sensePin, Type);

Arduino_ST7789 lcd = Arduino_ST7789(9, 10);
void setup() {
  lcd.init(240, 240); //initialize screen resolution
  lcd.fillScreen(BLACK); 
  lcd.setTextColor(RED);
  lcd.setTextSize(3);
  HT.begin();
}

void loop() {
  lcd.clearScreen();
  lcd.setCursor(0,0);
  lcd.print("Temperature: ");
  lcd.println(HT.readTemperature());
  lcd.print("Humidity: ");
  lcd.println(HT.readHumidity());
  delay(1000);
}
