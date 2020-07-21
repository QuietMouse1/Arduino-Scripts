// helpful link more than enough to understand https://www.arduino.cc/reference/en/language/functions/communication/serial/

// a more advanced guide https://www.arduino.cc/reference/en/language/functions/communication/stream/

//declare variable to store rpi command
String rpiCommand;

void setup() {
  // put your setup code here, to run once:
Serial.begin(9600); // Begins communication with RPI. 9600 is used to communicate from arduino to computers
pinMode(LED_BUILTIN, OUTPUT);
}


void loop() {
  // put your main code here, to run repeatedly:
  while (!Serial){}  // if a connection is not avaible , it will halt all the code here here. ! is a  NOT operator
  
  if (Serial.available()>0){  // once connection avaible 
    rpiCommand = Serial.readString(); // ONLY WORKS IF THE INCOMING SERIAL DATA IS IN THE FORM OF STRING. Check out the helpful link for more info
    Serial.println("Serial is avaible);
    if (rpiCommand == "OnLed")
    {
      digitalWrite(LED_BUILTIN, HIGH);   // turn the LED on (HIGH is the voltage level)
    }
    else 
    {
      digitalWrite(LED_BUILTIN, LOW);    // turn the LED off by making the voltage LOW
    }
 }
}
