#include <Servo.h>
#define buttonPinLeft = 10;
#define buttonPinRight = 8;

int buttonValueIncrease = 0;
int buttonValueDecrease = 0;

#define servoPin 12
Servo myServo;
int i = 0;

int speed = 100;
void setup() {
  pinMode(buttonPinLeft, INPUT);
  pinMode(buttonPinRight, INPUT);

  digitalWrite(buttonPinLeft, HIGH);
  digitalWrite(buttonPinRight, HIGH);
  
  myServo.attach(servoPin); //Servo pin
  Serial.begin(9600);
}

void loop() {
  buttonValueIncrease = digitalRead(buttonPinRight);
  if(!buttonValueIncrease && i < 180){
    i+=(speed/100);
    myServo.write(i);
  }
  
  buttonValueDecrease = digitalRead(buttonPin1);
  if(!buttonValueDecrease && i > 0){
    i-=(speed/100);
    myServo.write(i);
  }
  delay(10);
}