#define trigPin 2 
#define echoPin 3

#define buzzardPin 4

int pingTravelTime;
void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(buzzardPin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  //Send supersonic signal
  delay(100);
  digitalWrite(trigPin, LOW);
  delayMicroseconds(10);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);

  //Read supersonic signal
  pingTravelTime = pulseIn(echoPin, HIGH)/29/2;
  Serial.print(pingTravelTime); //print centimeters infront (can go without)
  Serial.println(" cm");

  if(pingTravelTime < 50) digitalWrite(buzzardPin, HIGH);
  else digitalWrite(buzzardPin, LOW);
}
