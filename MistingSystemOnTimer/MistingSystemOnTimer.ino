const unsigned long interval = 60; // 5 seconds interval (Adjust this value as needed)
int relayPin = 4;

unsigned long previousMillis = 0;
boolean relayState = false;

void setup() {
  pinMode(relayPin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  unsigned long currentMillis = millis();

  if (currentMillis - previousMillis >= interval * 1000) {
    relayState = !relayState; // Toggle relay state
    digitalWrite(relayPin, relayState);
    previousMillis = currentMillis;
    if (relayState) {
      Serial.println("OFF");
    } else {
      Serial.println("ON");
    }
  }
  delay(100);
}