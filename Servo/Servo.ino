#include <Servo.h>
int servoPin = 9;
Servo myServo;
void setup() {
  Serial.begin(9600);
  pinMode(servoPin,OUTPUT);
  myServo.attach(9);
}

void loop() {
  for(int i=0;i<180;i++){
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
