#include <Arduino_ST7789_Fast.h>
Arduino_ST7789 lcd = Arduino_ST7789(7, 8);

int potentiometerVal;
int prevValue;
void setup() {
  lcd.init(240, 240); //initialize screen resolution
  lcd.fillScreen(BLACK); 
  lcd.setTextColor(WHITE);
  lcd.setTextSize(3);
}

void loop() {
  potentiometerVal = analogRead(A0);
  if(prevValue != potentiometerVal)lcd.clearScreen();
  prevValue = potentiometerVal;
  lcd.setCursor(0, 0);
  lcd.println(potentiometerVal);  
  delay(1000);
}
