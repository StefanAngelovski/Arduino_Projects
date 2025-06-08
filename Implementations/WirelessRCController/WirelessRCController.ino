const byte UP_pin = 2;
const byte DOWN_pin = 3;
const byte LEFT_pin = 4;
const byte RIGHT_pin = 5;  

void setup() {
  Serial.begin(9600);
  pinMode(UP_pin, INPUT);
  pinMode(DOWN_pin, INPUT);
  pinMode(LEFT_pin, INPUT);
  pinMode(RIGHT_pin, INPUT);
}

void loop() {
  bool up = digitalRead(UP_pin);
  bool down = digitalRead(DOWN_pin);
  bool left = digitalRead(LEFT_pin);
  bool right = digitalRead(RIGHT_pin);

  Serial.print("Up is: ");
  Serial.print(up);
  Serial.println();

  Serial.print("Down is: ");
  Serial.print(down);
  Serial.println();

  Serial.print("Left is: ");
  Serial.print(left);
  Serial.println();

  Serial.print("Right is: ");
  Serial.print(right);
  Serial.println("\n========\n");
  delay(200);

}
