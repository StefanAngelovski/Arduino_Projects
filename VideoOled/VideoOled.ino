#include <Arduino_ST7789_Fast.h>
#define TFT_DC    7
#define TFT_RST   8 
#define SCR_WD   240
#define SCR_HT   240   // 320 - to allow access to full 240x320 frame buffer

Arduino_ST7789 lcd = Arduino_ST7789(TFT_DC, TFT_RST);
int tonePin = 2;

void setup() {
  Serial.begin(9600);
  lcd.init(SCR_WD, SCR_HT);
  lcd.fillScreen(BLACK);
  lcd.setTextColor(WHITE);
  lcd.setTextSize(3);
  randomSeed(analogRead(0));

  midi();
}

void loop() {
  lcd.fillRect(25, 42, 190, 160, WHITE);  // Draw the center rectangle
  drawStripes();
  delay(100);
}

void drawStripes() {
  for (int i = 0; i < SCR_HT; i++) {
    if (i % 27 == 0) {
      uint16_t color = lcd.color565(random(256), random(256), random(256));
      if (i < 25 || i >= 205) {
        lcd.fillRect(0, i, SCR_WD, 27, color);  // Draw full stripes outside the rectangle
      } else {
        if(i>25 && i<40){
          lcd.fillRect(0,i,SCR_WD,15,color); // Draw top
        }
        if(i>180 && i<205){
          lcd.fillRect(0,i+13,SCR_WD,15,color); // Draw bottom
        }
        lcd.fillRect(0, i, 25, 27, color);  // Draw the left portion of stripes outside the rectangle
        lcd.fillRect(215, i, 25, 27, color);  // Draw the right portion of stripes outside the rectangle
      }
    }
  }
}

void midi() {
  tone(tonePin, 369, 58.6956521739);
    delay(65.2173913043);
    delay(173.913043478);
    tone(tonePin, 246, 9.78260869565);
    delay(10.8695652174);
    tone(tonePin, 369, 176.086956522);
    delay(195.652173913);
    delay(108.695652174);
    tone(tonePin, 369, 185.869565217);
    delay(206.52173913);
    delay(119.565217391);
    tone(tonePin, 329, 136.956521739);
    delay(152.173913043);
    tone(tonePin, 987, 9.78260869565);
    delay(10.8695652174);
    delay(152.173913043);
    delay(10.8695652174);
    tone(tonePin, 369, 29.347826087);
    delay(32.6086956522);
    delay(119.565217391);
    tone(tonePin, 1318, 9.78260869565);
    delay(10.8695652174);
    tone(tonePin, 440, 29.347826087);
    delay(32.6086956522);
    tone(tonePin, 369, 166.304347826);
    delay(184.782608696);
    delay(119.565217391);
    delay(10.8695652174);
    tone(tonePin, 987, 136.956521739);
    delay(152.173913043);
    delay(43.4782608696);
    delay(206.52173913);
    tone(tonePin, 1108, 68.4782608696);
    delay(76.0869565217);
    tone(tonePin, 369, 39.1304347826);
    delay(43.4782608696);
    delay(293.47826087);
    delay(97.8260869565);
    tone(tonePin, 880, 39.1304347826);
    delay(43.4782608696);
    delay(173.913043478);
    delay(108.695652174);
    tone(tonePin, 880, 39.1304347826);
    delay(43.4782608696);
    delay(184.782608696);
    tone(tonePin, 880, 136.956521739);
    delay(152.173913043);
    delay(21.7391304348);
    delay(65.2173913043);
    delay(10.8695652174);
    tone(tonePin, 830, 29.347826087);
    delay(32.6086956522);
    tone(tonePin, 1396, 29.347826087);
    delay(32.6086956522);
    delay(184.782608696);
    delay(65.2173913043);
    tone(tonePin, 1396, 68.4782608696);
    delay(76.0869565217);
    delay(184.782608696);
    delay(86.9565217391);
    tone(tonePin, 1396, 48.9130434783);
    delay(54.347826087);
    tone(tonePin, 987, 156.52173913);
    delay(173.913043478);
    tone(tonePin, 329, 9.78260869565);
    delay(10.8695652174);
    delay(152.173913043);
    tone(tonePin, 349, 283.695652174);
    delay(315.217391304);
    tone(tonePin, 1046, 9.78260869565);
    delay(10.8695652174);
    tone(tonePin, 1108, 215.217391304);
    delay(239.130434783);
    delay(76.0869565217);
    tone(tonePin, 1108, 146.739130435);
    delay(163.043478261);
    tone(tonePin, 369, 68.4782608696);
    delay(76.0869565217);
}