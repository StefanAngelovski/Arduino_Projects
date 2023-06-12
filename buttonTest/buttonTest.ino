const int buttonPin = 3;    // Pin number for the pushbutton
int buttonState = HIGH;     // Current state of the button
int lastButtonState = HIGH; // Previous state of the button

void setup() {
  pinMode(buttonPin, INPUT_PULLUP); // Set the button pin as INPUT with internal pull-up resistor
  Serial.begin(9600);
}

void loop() {
  buttonState = digitalRead(buttonPin); // Read the current state of the button
  Serial.println("NOT");
  // Check for a button release
  if (buttonState == HIGH && lastButtonState == LOW) {
    // Button has been released
    // Perform your desired actions here
    Serial.println("RELEASED");
  }

  lastButtonState = buttonState; // Store the current state for the next iteration
}