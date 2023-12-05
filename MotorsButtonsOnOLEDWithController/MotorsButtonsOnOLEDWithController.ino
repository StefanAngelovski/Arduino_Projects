#include <Arduino_ST7789_Fast.h>
#include <MX1508.h>

//#define PINA 9
//#define PINB 10
#define PINC 5
#define PIND 6

#define NUMPWM 2
//MX1508 motorA(PINA,PINB, FAST_DECAY, NUMPWM);
MX1508 motorB(PINC,PIND, FAST_DECAY, NUMPWM);
Arduino_ST7789 lcd = Arduino_ST7789(9,12);

int pwm = 0;
const int buttonLeft = 3;
const int buttonRight = 2;

void setup() {
  lcd.init(240, 240);
  lcd.fillScreen(BLACK);
  lcd.setTextColor(RED);
  lcd.setTextSize(3);

  Serial.begin(9600);
  pinMode(buttonLeft, INPUT);
  pinMode(buttonRight, INPUT);
  digitalWrite(buttonLeft, HIGH);
  digitalWrite(buttonRight, HIGH);
}

void loop() {
  int buttonLeftState = digitalRead(buttonLeft);
  if(pwm==0) delay(500);
  if (!buttonLeftState && pwm > -255) {
    pwm-=5;
    //lcd.clearScreen();
  }
  int buttonRightState = digitalRead(buttonRight);
  if (!buttonRightState && pwm < 255) {
    pwm+=5;
    //lcd.clearScreen();
  }
  delay(100);

  // Update motor speed
  motorB.motorGo(pwm);
  Serial.println(pwm);
  //lcd.setCursor(0,0);
  //lcd.println(pwm);
  //LCD TAKES TOO MUCH POWAH!
}