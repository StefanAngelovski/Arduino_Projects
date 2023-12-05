const int trigPin = 2; 
const int echoPin = 3;
int pingTravelTime;
void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  Serial.begin(9600);
}

void loop() {
  //Send supersonic signal
  delay(1000);
  digitalWrite(trigPin, LOW);
  delayMicroseconds(10);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);

  //Read supersonic signal
  pingTravelTime = pulseIn(echoPin, HIGH);
  Serial.print(pingTravelTime / 29 / 2); //print centimeters infront (can go without)
  Serial.println(" cm");
}
