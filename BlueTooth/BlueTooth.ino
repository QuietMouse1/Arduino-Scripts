/* The code is to control a simple LED light to switch it off and on via bluetooth. This is done via a couple of if statements and 2 variable that store the state of the bluetooth.
state ==  1 results in LED light switching on, state == 0 - results in LED light switching off
flag is used as to ensure that a block of conditional code only runs once despite it always being true and being looped. 
The android App could be downloaded from the playstore.


IMPT NOTES
-When uploading sketch to arduino, make sure the TX RX serial port is disconnected from any wires OTHERWISE THE UPLOADING WILL NOT WORK!

*/ 
//copied from http://www.tinkernut.com/2014/03/arduino-bluetooth-basics/

int ledPin = 13; 
int state = 0;  
int flag = 0; 
 
void setup() {
 pinMode(ledPin, OUTPUT);
 digitalWrite(ledPin, LOW);
 Serial.begin(9600); // Default connection rate for my BT module
}
 
void loop() {
 if(Serial.available() > 0){  //Get the number of bytes (characters) available for reading from the serial port A.K.A Check if any there is any command given to the the bluetooth  
   state = Serial.read();  // read any command given to the bluetooth
   flag=0; //resets the flag to 0 again.   
 }

 if (state == '0') { 
   digitalWrite(ledPin, LOW); //switch LED off
   if(flag == 0){ // a simple conditional to make sure the code below only runs once.
     Serial.println("LED: off");
     flag = 1;}
 }
 
 else if (state == '1') {
   digitalWrite(ledPin, HIGH);
   if(flag == 0){
     Serial.println("LED: on");
     flag = 1;}
 }
}
