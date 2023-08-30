// Constants

const int RED_PIN = 5;  // Red LED connected to pin 5
const int GREEN_PIN = 4;   //Green LED connected to pin 5
const int BLUE_PIN = 3;   //Blue LED connected to pin 5
const int SWITCH_PIN = 6; // Switch pin 6
const int BUTTON_PIN = 7;  // Connect the Button to pin 7 or change here
const int RELAY_PIN    = 8; // Connection to relay HERE

// Variables

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


  // === === === ===   Start-up LED Sequence
  setColor(255,0,0); //Red LED
  delay(250);        //Time delay
  setColor(0,0,0);   //No color LED
  delay(250); 
  setColor(255,0,0);
  delay(250);
  setColor(0,0,0); 
  delay(250); 
  setColor(255,0,0); 
  delay(250);
  setColor(0,0,0); 
}


void loop() {
// put your main code here, to run repeatedly:
  if(digitalRead(SWITCH_PIN) == HIGH){
    digitalWrite(RED_PIN, HIGH);
  }
    else {
      digitalWrite(RED_PIN, LOW);
  }

lastButtonState    = currentButtonState;      // save the last state
currentButtonState = digitalRead(BUTTON_PIN); // read new state

if(lastButtonState == HIGH && currentButtonState == LOW && digitalRead (SWITCH_PIN)== HIGH) {
  
  Serial.println("Launch");
  // Add serial.print Time/Date/Time/Humid./Alt.
  
  if(relayState == LOW) // If relay low,
    relayState = HIGH;  // Switch relay to HIGH
      else
        relayState = LOW; // Otherwise, keep relay LOW
  digitalWrite(RELAY_PIN, relayState); // Controls relay arccoding to the toggled state
  }
}





// SetColor Setup 
void setColor(int R, int G, int B) {
analogWrite(RED_PIN,   R);
analogWrite(GREEN_PIN, G);
analogWrite(BLUE_PIN,  B);
}
