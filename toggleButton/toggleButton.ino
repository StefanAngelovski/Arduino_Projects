bool buttonState = 0;    // Switch on or off
bool currentState = 0;   // State of being pressed

//for debouncing
bool prevState = 0;
void setup() {
  pinMode(3,INPUT);
  pinMode(4,OUTPUT);
  Serial.begin(9600);
}

void loop() {
  currentState = digitalRead(3);
  delay(100);

  //With debouncing
  if(prevState && !currentState){  // 0 0 1 1 [1 0]
    if(buttonState){
      buttonState = 0;
      digitalWrite(4,LOW);
    } else {
      buttonState = 1;
      digitalWrite(4,HIGH);
    }
    Serial.println("Released");
  } 
  prevState = currentState;

  buttonState?Serial.println("ON"):Serial.println("OFF");
}
