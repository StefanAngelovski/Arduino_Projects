int dataPin = 4;
int latchPin = 3;
int clockPin = 2;

byte LEDs = B00000001; //Which LEDs to turn HIGH
void setup() {
  pinMode(dataPin,OUTPUT);  //OUTPUT PINS
  pinMode(latchPin,OUTPUT); //Whether your latch is on or off
  pinMode(clockPin,OUTPUT); //Keep it sync - Don't worry
  Serial.begin(9600);
}

void loop() {
  Serial.println(LEDs);
  LEDs = LEDs*2+LEDs/32;
  digitalWrite(latchPin, LOW); //Start sending data
  shiftOut(dataPin, clockPin, MSBFIRST, LEDs); 
  digitalWrite(latchPin, HIGH); //Stop sending data
  Serial.println(LEDs,BIN);
  delay(2000);
}
