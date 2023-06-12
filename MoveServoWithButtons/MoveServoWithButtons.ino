#include <Servo.h>
int buttonPin1 = 10;
int buttonPin2 = 8;
int buttonValueIncrease = 0;
int buttonValueDecrease = 0;
Servo myServo;
int i = 0;

int speed = 100;
void setup() {
  pinMode(buttonPin1,INPUT);
  pinMode(buttonPin2,INPUT);

  digitalWrite(buttonPin1,HIGH);
  digitalWrite(buttonPin2,HIGH);
  
  myServo.attach(12);
  Serial.begin(9600);
}

void loop() {
  buttonValueIncrease = digitalRead(buttonPin2);
  if(!buttonValueIncrease && i<180){
    i+=(speed/100);
    myServo.write(i);
  }
  
  buttonValueDecrease = digitalRead(buttonPin1);
  if(!buttonValueDecrease && i>0){
    i-=(speed/100);
    myServo.write(i);
  }
  delay(10);
}