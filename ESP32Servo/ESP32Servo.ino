#include <ESP32Servo.h>
byte potentiometerPin = 15;
byte servoPin = 4;
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
