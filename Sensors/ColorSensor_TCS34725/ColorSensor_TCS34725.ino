#include <Wire.h>
#include "Adafruit_TCS34725.h"

// Define I2C pins (SDA = 4, SCL = 5)
#define SDA_PIN 4
#define SCL_PIN 5

// Initialize sensor with specific integration time and gain
Adafruit_TCS34725 tcs = Adafruit_TCS34725(TCS34725_INTEGRATIONTIME_24MS, TCS34725_GAIN_4X);

void setup() {
  Serial.begin(115200);
  Wire.begin(SDA_PIN, SCL_PIN); // Start I2C with custom pins

  if (!tcs.begin()) {
    Serial.println("Sensor not found. Check wiring!");
    while (1); // Halt if sensor fails
  }
  Serial.println("TCS34725 RGB sensor ready!");
}

void loop() {
  uint16_t r, g, b, c;
  
  tcs.getRawData(&r, &g, &b, &c); // Read raw sensor data
  Serial.printf("R: %d, G: %d, B: %d, C: %d\n", r, g, b, c);
  if(r > 150)Serial.println("----RED----");
  if(g > 150)Serial.println("----GREEN----");
  if(b > 150)Serial.println("----BLUE----");
  
  delay(500); // Adjust delay as needed
}