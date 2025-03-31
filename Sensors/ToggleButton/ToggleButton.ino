// This sketch is for a toggle button. When the button is pressed, it toggles the state of the LED.

#define buttonPin 3 // Pin where the button is connected
#define ledPin 4    // Pin where the LED is connected

bool buttonState = 0;    // Switch on or off
bool currentState = 0;   // State of being pressed

//for debouncing
bool prevState = 0;
void setup() {
  pinMode(buttonPin, INPUT);
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  currentState = digitalRead(buttonPin);
  delay(100);

  //With debouncing
  if(prevState && !currentState){  // 0 0 1 1 [1 0]
    if(buttonState){
      buttonState = 0;
      digitalWrite(ledPin, LOW);
    } else {
      buttonState = 1;
      digitalWrite(ledPin, HIGH);
    }
    Serial.println("Released");
  } 
  prevState = currentState;

  buttonState?Serial.println("ON"):Serial.println("OFF");
}
