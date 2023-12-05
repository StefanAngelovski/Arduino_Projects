byte sensorPin = 2;
void setup() {
  pinMode(sensorPin,INPUT);
  Serial.begin(9600);
}

void loop() {
  Serial.println(digitalRead(sensorPin));
  delay(100);
}
