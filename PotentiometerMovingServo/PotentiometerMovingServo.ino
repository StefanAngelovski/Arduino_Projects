#include <Servo.h>
Servo myServo;

int potentiometerVal=0;
int prevValue=0;
void setup() {
  myServo.attach(4);
}

void loop() {
  potentiometerVal = analogRead(A0);
  if(prevValue!=potentiometerVal)myServo.write((int)(potentiometerVal  * 0.1761)); 
  prevValue = potentiometerVal;
  delay(10);
}
