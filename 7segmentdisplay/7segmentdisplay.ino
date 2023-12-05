#include <TM1637Display.h>

// Module connection pins (Digital Pins)
#define CLK 2
#define DIO 3

TM1637Display display(CLK, DIO); //initialize display
void setup() {
    display.setBrightness(0x02); //sets brightness level in hex (from 0 to f)
    //display.showNumberDec(25, true);     //replace number decimal with the thing you want to display
}

void loop() {
  for(int i=0;i<9999;i++){
    display.showNumberDec(i, true);
    delay(1000);
  }
}
