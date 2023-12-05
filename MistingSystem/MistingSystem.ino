#include <DHT.h>
#define Type DHT11
const unsigned int sensePin = 2;
DHT HT(sensePin, Type);
const unsigned int relayPin = 4;
int humidityVal;

bool isActive = true;
void setup() {
  pinMode(relayPin, OUTPUT);
  Serial.begin(9600);
  HT.begin();
}

void loop() {
  humidityVal = HT.readHumidity();
  Serial.println(humidityVal);

  if (humidityVal >= 90) {
    digitalWrite(relayPin, HIGH); // Turn off, reached MAX
    isActive = false;
  } else if (isActive) {
    digitalWrite(relayPin, LOW); // Turn on till MAX
  } else if (humidityVal <= 80) {
    digitalWrite(relayPin, HIGH); // Turn on when MIN
    isActive = true; // Reset isActive to true when humidity drops below 80
  }
  delay(2000);
}
