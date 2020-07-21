//Unity controller. Player 1 = 2,3,4  Player 2 = 5,6,7  Player 3 = 8,9,10
//Data is sent in human-readable ASCII text.

byte buttonState;

unsigned long lastDebounceTime2 = 0;  // the last time the output pin was toggled
unsigned long lastDebounceTime3 = 0;  // the last time the output pin was toggled
unsigned long lastDebounceTime4 = 0;  // the last time the output pin was toggled
unsigned long lastDebounceTime5 = 0;  // the last time the output pin was toggled
unsigned long lastDebounceTime6 = 0;  // the last time the output pin was toggled
unsigned long lastDebounceTime7 = 0;  // the last time the output pin was toggled
unsigned long lastDebounceTime8 = 0;  // the last time the output pin was toggled
unsigned long lastDebounceTime9 = 0;  // the last time the output pin was toggled
unsigned long lastDebounceTime10 = 0;  // the last time the output pin was toggled
unsigned long lastDebounceTimeArray [] = {lastDebounceTime2,lastDebounceTime3,lastDebounceTime4,lastDebounceTime5,lastDebounceTime6,lastDebounceTime7,lastDebounceTime8,lastDebounceTime9,lastDebounceTime10};

int debounceDelay = 20;    // the debounce time; increase if the output flickers

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  for( int thisButton = 2 ; thisButton < 11 ; thisButton++)
  {
    pinMode(thisButton,INPUT);
    Serial.println(thisButton,DEC);
  }
}

void loop() {
  //Check for debounce and state of pin
    for( int thisButton = 2 ; thisButton < 11 ; thisButton++){
      buttonState = digitalRead(thisButton);
      if(millis() - lastDebounceTimeArray[thisButton-2] > debounceDelay){
        lastDebounceTimeArray[thisButton-2] = millis();    // reset the timer
        if (buttonState == HIGH){
          Serial.write(thisButton);
          }
        }
        else{
          Serial.write(thisButton);
        }
      }
  }
