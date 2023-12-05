const int IRPin = 2;
void setup() {
  pinMode(IRPin, INPUT);
  Serial.begin(9600);
}

void loop() {
  if(digitalRead(IRPin) == LOW){
    Serial.println("No");
  } else {
    Serial.println("Yes");
  }
}
