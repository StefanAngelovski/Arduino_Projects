#include <string.h>
#include <Arduino_ST7789_Fast.h>
#define TFT_DC    7
#define TFT_RST   8 
#define SCR_WD   240
#define SCR_HT   240   // 320 - to allow access to full 240x320 frame buffer
Arduino_ST7789 lcd = Arduino_ST7789(TFT_DC, TFT_RST);








String example;

void setup(void) 
{
  Serial.begin(9600);
  lcd.init(SCR_WD, SCR_HT); //initialize screen resolution
  lcd.fillScreen(BLACK); 
  lcd.setTextColor(WHITE);
  lcd.setTextSize(3);
 }

void loop()
{
  while(Serial.available()==0){}
  example = Serial.readString();
  lcd.setCursor(0, 0);
  lcd.clearScreen();
  
  lcd.println(example);
}

