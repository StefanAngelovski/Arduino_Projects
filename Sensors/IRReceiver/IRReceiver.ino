#include <IRremote.hpp>

#define RECV_PIN 4  // Using stable GPIO4

uint32_t irHexCode = 0;

void setup() {
  Serial.begin(115200);
  IrReceiver.begin(RECV_PIN, DISABLE_LED_FEEDBACK);
  Serial.println("IR Receiver Ready");
}

void loop() {
  if (IrReceiver.decode()) {
    if (IrReceiver.decodedIRData.protocol != UNKNOWN) {
      irHexCode = IrReceiver.decodedIRData.command;  // Value stored here
      Serial.print("Stored HEX: 0x");
      Serial.println(irHexCode, HEX);
    }
    IrReceiver.resume();
    delay(100);
  }  
}