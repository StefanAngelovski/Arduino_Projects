int ledPins[] = {6,7,8,9,10};
int buttonPinDecrease = 3;
int buttonPinIncrease = 11;

bool currentStateD = 0;
bool currentStateI = 0;

bool prevStateD = 0;
bool prevStateI = 0;
//////////////////////
int i = 0;
void setup() {
  for(int i=0;i<5;i++){
    pinMode(ledPins[i],OUTPUT);
  }

  pinMode(buttonPinDecrease,INPUT);
  digitalWrite(buttonPinDecrease,HIGH);
  
  pinMode(buttonPinIncrease,INPUT);
  digitalWrite(buttonPinIncrease,HIGH);

  Serial.begin(9600);
}

void loop() {
  currentStateD = digitalRead(buttonPinDecrease);
  currentStateI = digitalRead(buttonPinIncrease);
  delay(100);


  if(i>0){
    //debouncing decrease button
    if(prevStateD && !currentStateD){  // 0 0 1 1 1 [1 0]
      i--;
      Serial.print("DECREASE ");
      Serial.println(i+1);
    }
    prevStateD = currentStateD;
  }

  if(i<4){
    //debouncing increase button
    if(prevStateI && !currentStateI){
      i++;
      Serial.print("INCREASE ");
      Serial.println(i+1);
    }
    prevStateI = currentStateI;
  }

  // switch through LEDs
  for(int j=0;j<5;j++){
    if(j!=i){
      digitalWrite(ledPins[j],LOW);
    } 
    analogWrite(ledPins[i],255);
  }

}
