const int RED_PIN = 5;  // Red LED connected to pin 5
const int GREEN_PIN = 4;   //Green LED connected to pin 5
const int BLUE_PIN = 3;   //Blue LED connected to pin 5
const int SWITCH_PIN = 6; // Switch pin 6
const int BUTTON_PIN = 7;  // Connect the Button to pin 7 or change here
const int RELAY_PIN    = 8; // Connection to relay HERE
// Variables that will change:

int relayState = LOW;     // tracks the current state of LED
int lastButtonState;    // the previous state of button
int currentButtonState; // the current state of button

void setup() {

// Code, to run once:

Serial.begin(9600);                // initialize serial
pinMode(RED_PIN, OUTPUT);
pinMode(GREEN_PIN, OUTPUT);
pinMode(BLUE_PIN, OUTPUT);
pinMode(BUTTON_PIN, INPUT_PULLUP); // set arduino pin to input pull-up mode
pinMode(SWITCH_PIN, INPUT_PULLUP);
pinMode(RELAY_PIN, OUTPUT);          // RELAY Pin output...for when you need it.

// currentButtonState = digitalRead(BUTTON_PIN);


// Start-up Sequence
 /* setColor(255,0,0);
  delay(250);        
  setColor(0,0,0);   
  delay(250);
  setColor(255,0,0);
  delay(250);
  setColor(0,0,0); 
  delay(250); 
  setColor(255,0,0); 
  delay(250);
  setColor(0,0,0); 
  delay(1000); 
*/
  setColor(89,14,145); //Purple
  delay(3000); 
  setColor(0,238,8);  // White/Grey
  delay(2000); 
  setColor(0,0,255); //Blue
  delay(1000);

  setColor(0,255,0); 
  delay(250); 
  setColor(0,0,255); 
  delay(250); 
  setColor(0,0,0); 
}


void loop() {
// put your main code here, to run repeatedly:
  if(digitalRead(SWITCH_PIN)== HIGH){
    digitalWrite(RED_PIN, HIGH);
  }
    else {
      digitalWrite(RED_PIN, LOW);
  }

lastButtonState    = currentButtonState;      // save the last state
currentButtonState = digitalRead(BUTTON_PIN); // read new state

if(lastButtonState == HIGH && currentButtonState == LOW && digitalRead (SWITCH_PIN)== HIGH) {
Serial.println("Launch");


// toggle state of LED
if(relayState == LOW)
relayState = HIGH;
else
relayState = LOW;

// control relay arccoding to the toggled state
digitalWrite(RELAY_PIN, relayState); 
}


}





// SetColor Setup 
void setColor(int R, int G, int B) {
analogWrite(RED_PIN,   R);
analogWrite(GREEN_PIN, G);
analogWrite(BLUE_PIN,  B);
}
