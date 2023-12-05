#include <Arduino_ST7789_Fast.h>
Arduino_ST7789 lcd = Arduino_ST7789(7, 8);

int count=0;
int potentiometerVal;
int prevValue;
void setup() {
  lcd.init(240, 240); //initialize screen resolution
  lcd.fillScreen(BLACK); 
  lcd.setTextColor(WHITE);
  lcd.setTextSize(3);
  Serial.begin(9600);
}

void loop() {
  potentiometerVal = analogRead(A0);
  count = potentiometerVal * 6/1022;
  if(prevValue-potentiometerVal>75 || potentiometerVal-prevValue>75)lcd.clearScreen();
  prevValue = potentiometerVal;
  lcd.setCursor(110,0);
  lcd.setTextColor(RED);
  for(int i=0;i<count && i<5;i++){
    //Left
    lcd.setCursor(110-(i*25),110);
    lcd.println("#");

    //Right
    lcd.setCursor(110+(i*25),110);
    lcd.println("#");

    //Up
    lcd.setCursor(110,110-(i*25));
    lcd.println("#");

    //Down
    lcd.setCursor(110,110+(i*25));
    lcd.println("#");
  }
  
  delay(500);
}
