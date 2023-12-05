int xPin = A0;
int yPin = A1;
int switchPin = 2;

int xVal, yVal, sVal;
void setup() {
  Serial.begin(9600);
  pinMode(xPin, INPUT);
  pinMode(yPin, INPUT);
  pinMode(switchPin, INPUT);
  digitalWrite(switchPin, HIGH); //Simulate pull up resistor
}

void loop() {
  xVal = analogRead(xPin);
  yVal = analogRead(yPin);
  sVal = !digitalRead(switchPin);
  delay(100);
  Serial.print("X: ");
  Serial.print(xVal);
  Serial.print(" Y: ");
  Serial.print(yVal);
  Serial.print(" Switch: ");
  Serial.print(sVal);
  Serial.println();
}
