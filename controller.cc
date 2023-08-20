// Constants
const int BUTTON_PIN = 7;  // Connect the Button to pin 7 or change here
const int RELAY_PIN    = 3; // Connect the LED to pin 3 or change here
  
// Variables 
int relayState = LOW;     // tracks the current state of LED
int lastButtonState;    // the previous state of button
int currentButtonState; // the current state of button
  
void setup() {
  Serial.begin(9600);                // initialize serial
  pinMode(BUTTON_PIN, INPUT_PULLUP); // set arduino pin to input pull-up mode
  pinMode(RELAY_PIN, OUTPUT);          // set arduino pin to output mode
  
  currentButtonState = digitalRead(BUTTON_PIN);
}
  
void loop() {
  lastButtonState    = currentButtonState;      // save the last state
  currentButtonState = digitalRead(BUTTON_PIN); // read new state
  
  if(lastButtonState == HIGH && currentButtonState == LOW) {
    Serial.println("The button is pressed");
  
    // toggle state of LED
    if(relayState == LOW)
       relayState = HIGH;
    else
      relayState = LOW;
  
    // control relay arccoding to the toggled state
    digitalWrite(RELAY_PIN, relayState); 
  }
}
