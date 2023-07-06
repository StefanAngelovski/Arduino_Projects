#include <Arduino_ST7789_Fast.h>
#include <LinkedList.h>
#include <string.h>
Arduino_ST7789 lcd = Arduino_ST7789(7, 8);




/*void bracket(){
  bracket();
}*/


// Initialization
int start, end, result;
bool state;
String example;


void setup(void) 
{
  Serial.begin(9600);
  lcd.init(240, 240); //initialize screen resolution
  lcd.fillScreen(BLACK); 
  lcd.setTextColor(WHITE);
  lcd.setTextSize(3);
  
  lcd.println("Calculator");
  lcd.println("===========");
 }

void loop()
{
  while(Serial.available()==0){}

  //Resetting 
  start=0, end=0, result=0; state=false;
  LinkedList<int> linky = LinkedList<int>();
  LinkedList<char> operators = LinkedList<char>();
  example = Serial.readString();

  //Analyzing text
  for(int i=0;i<example.length();i++){
     if(isdigit(example[i])){
         if(!state){
             state=true; 
             start = i; 
        }
        if(state && (i==example.length()-1 || !isdigit(example[i+1]))){
            state=false;
            end=i+1;
            linky.add(example.substring(start,end).toInt()); //ADD to list
        }
      } else {
        operators.add(example[i]);
     }
  }

  //Calculating everything
  result = linky[0];
  for(int i=0;i<operators.size();i++){
      switch(operators[i]){
          case '+': result+=linky[i+1]; break;
          case '-': result-=linky[i+1]; break;
          case '*': result*=linky[i+1]; break;
          case '/': result/=linky[i+1]; break;
      }
  }

  example.trim();
  lcd.println(example + " = " + result);
  lcd.println("=======");
  delay(200);
}

