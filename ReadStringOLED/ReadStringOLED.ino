#include <string.h>
#include <Arduino_ST7789_Fast.h>
#include <Vector.h>
#define TFT_DC    7
#define TFT_RST   8 
#define SCR_WD   240
#define SCR_HT   240   // 320 - to allow access to full 240x320 frame buffer
Arduino_ST7789 lcd = Arduino_ST7789(TFT_DC, TFT_RST);










void setup(void) 
{
  Serial.begin(9600);
  lcd.init(SCR_WD, SCR_HT); //initialize screen resolution
  lcd.fillScreen(BLACK); 
  lcd.setTextColor(WHITE);
  lcd.setTextSize(3);
 }

void loop()
{
  while(Serial.available()==0){}
  lcd.setCursor(0, 0);
  lcd.clearScreen();


  int start=0, end=0, result=0;
    bool state=false;
    Vector<int> linky;
    Vector<char> operators;
    String example;
    example = Serial.readString();
    for(int i=0;i<example.length();i++){
        if(isdigit(example[i])){
            if(!state){
                state=true; 
                start = i; 
            }
            if(state && (i==example.length()-1 || !isdigit(example[i+1]))){
                state=false;
                end=i+1;
                linky.push_back((example.substring(start,end-start).toInt())); //ADD to list
            }
        } else {
            operators.push_back(example[i]);
        }
    }

    result = linky[0];
    for(int i=0;i<operators.size();i++){
        switch(operators[i]){
            case '+': result+=linky[i+1]; break;
            case '-': result-=linky[i+1]; break;
            case '*': result*=linky[i+1]; break;
            case '/': result/=linky[i+1]; break;
        }
    }
    lcd.println(result);
  delay(200);
}

