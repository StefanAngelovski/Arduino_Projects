#include <Servo.h>

#define servoPin 4
#define potentiometerPin A0

int potentiometerVal=0;
int prevValue=0;

Servo myServo;

void setup() {
  myServo.attach(servoPin);
}

void loop() {
  potentiometerVal = analogRead(potentiometerPin);
  if(prevValue!=potentiometerVal)myServo.write((int)(potentiometerVal  * 0.1761)); 
  prevValue = potentiometerVal;
  delay(10);
}
