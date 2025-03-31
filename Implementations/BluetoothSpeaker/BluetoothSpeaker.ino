// Might Require an older board version of ESP32
#include "esp32_bt_music_receiver.h"

BluetoothA2DSink a2dp_sink; //Initialize bluetooth speaker library

void setup() {
    a2dp_sink.start("Phys Boombox"); //Start bluetooth with the name in ""
}

void loop() {
}