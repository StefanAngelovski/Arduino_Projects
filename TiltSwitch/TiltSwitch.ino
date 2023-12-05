int tiltPin = 2;
void setup() {
  Serial.begin(9600);
  pinMode(tiltPin, INPUT);
  digitalWrite(tiltPin, HIGH);
}

void loop() {
  digitalRead(tiltPin)?Serial.println("Tilted"):Serial.println("Not Tilted");
  delay(100);
}
