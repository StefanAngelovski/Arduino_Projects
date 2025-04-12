y// Define the pin numbers for the Soil humidity sensor
const int sensorPin = 4;

void setup() {
  Serial.begin(9600);  // Start serial communication at 9600 baud rate
}

void loop() {
  Serial.println(analogRead(sensorPin)); //Inverse value
  delay(100);                             
}
