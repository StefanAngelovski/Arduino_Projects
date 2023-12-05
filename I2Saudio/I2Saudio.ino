//Playing different online music from ESP32
#include "Arduino.h"
#include "Audio.h"
#include "SPI.h"
#include "FS.h"

#include <WiFiManager.h>
WiFiManager wm;

// Digital I/O used
#define I2S_DOUT      21
#define I2S_BCLK      22
#define I2S_LRC       19

// Buttons
#define buttonLeft 4
#define buttonRight 15
byte prevLeft = digitalRead(buttonLeft);
byte prevRight = digitalRead(buttonRight);
int i = 0;

//GTA SA Music ;)
String currentMusic [11] = {"k-rose", "bounce-fm", "csr", "k-dst", "k-jah", "master-sounds", "playback-fm", "radio-los-santos", "radio-x", "sfur", "wctr"};
Audio audio;

void setup() {
    pinMode(buttonLeft, OUTPUT);
    digitalWrite(buttonLeft, HIGH);

    pinMode(buttonRight, OUTPUT);
    digitalWrite(buttonRight, HIGH);

    Serial.begin(115200);
    WiFi.mode(WIFI_STA);
    wm.autoConnect("HeyB");
    if(WiFi.status() != WL_CONNECTED){
        WiFi.disconnect(true);
        wm.autoConnect();
    }
    audio.setPinout(I2S_BCLK, I2S_LRC, I2S_DOUT);
    audio.setVolume(21); // 0...21

    audio.connecttohost("https://play.smolyakov.dev/stream/sa/k-rose"); //Custom GTA tracks :)
  //audio.connecttohost("https://physnet.000webhostapp.com/uploads/audio.mp3"); //Custom tracks through wifi
}

void loop()
{
    String music = "https://play.smolyakov.dev/stream/sa/";
    if(prevRight && !digitalRead(buttonRight)){
      audio.stopSong();
      if(i==11)i=-1;
      music.concat(currentMusic[++i]);
      audio.connecttohost(music.c_str());
    }
    prevRight = digitalRead(buttonRight);

    if(prevLeft && !digitalRead(buttonLeft)){
      audio.stopSong();
      if(i==0)i=11;
      music.concat(currentMusic[--i]);
      audio.connecttohost(music.c_str());
    }
    prevLeft = digitalRead(buttonLeft);
    audio.loop();
    if(Serial.available()){ // put streamURL in serial monitor
        audio.stopSong();
        String r=Serial.readString(); r.trim();
        if(r.length()>5) audio.connecttohost(r.c_str());
        log_i("free heap=%i", ESP.getFreeHeap());
    }
}

// optional
void audio_info(const char *info){
    Serial.print("info        "); Serial.println(info);
}
void audio_id3data(const char *info){  //id3 metadata
    Serial.print("id3data     ");Serial.println(info);
}
void audio_eof_mp3(const char *info){  //end of file
    Serial.print("eof_mp3     ");Serial.println(info);
}
void audio_showstation(const char *info){
    Serial.print("station     ");Serial.println(info);
}
void audio_showstreamtitle(const char *info){
    Serial.print("streamtitle ");Serial.println(info);
}
void audio_bitrate(const char *info){
    Serial.print("bitrate     ");Serial.println(info);
}
void audio_commercial(const char *info){  //duration in sec
    Serial.print("commercial  ");Serial.println(info);
}
void audio_icyurl(const char *info){  //homepage
    Serial.print("icyurl      ");Serial.println(info);
}
void audio_lasthost(const char *info){  //stream URL played
    Serial.print("lasthost    ");Serial.println(info);
}
