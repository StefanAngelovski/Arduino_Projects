// Define the pin numbers for the Gas Sensor
const int sensorPin = 4;

void setup() {
  Serial.begin(9600);  // Start serial communication at 9600 baud rate
}

void loop() {
  Serial.println(analogRead(sensorPin)>2100?"Opasnost":"");
  delay(100);                             
}
