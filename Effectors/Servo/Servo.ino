#include <Servo.h>
#define servoPin 9
// This sketch is for a servo motor. 
// It sweeps the servo from 0 to 180 degrees and back to 0 degrees.

Servo myServo;
void setup() {
  Serial.begin(9600);
  pinMode(servoPin, OUTPUT);
  myServo.attach(servoPin);
}

void loop() {
  for(int i=0; i < 180; i++){
    myServo.write(i);
    delay(50);
    if(i==179){
      while(i!=0){
        i--;
        myServo.write(i);
        delay(50);
      }
    }
  }

}
