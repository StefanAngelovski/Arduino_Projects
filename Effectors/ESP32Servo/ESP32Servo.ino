// This sketch is for a servo motor. It reads the value from a potentiometer
// and sets the position of the servo motor accordingly.

#include <ESP32Servo.h>

#define potentiometerPin = 15;
#define servoPin = 4;

Servo servo;
void setup() {
  Serial.begin(9600);
  servo.attach(servoPin);

}

void loop() {
  int potentiometer = analogRead(potentiometerPin);
  Serial.println(potentiometer);
  servo.write(180 - (potentiometer * (180/4095.0)));
}
