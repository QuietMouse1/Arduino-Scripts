/*
The code below are for multiple HC-SR004 sensors. The pin numbers are stored in two data arrays, echoPins and triPins. The first index of each array should be located side by side on the Arduino board
for simplicity. 

IMPT NOTES-
if one of the senors do not recieve any reflected ultra sound on the echo side, the loop will take 1 second to complete! This is probably due to the variable distance which has a "long" data type.
ledPin is for a conditional distance , eg if distance is smaller than x.
*/
// Stores the ECHO / TRIGGER pins into arrays
int echoPins[] = {52,50,48};  //ADD MORE when using MEGA BOARD  
int trigPins[] = {53,51,49};  //ADD MORE when using MEGA BOARD
int sensorNumber = 3; // change this number to number of sensors
int ledPin = 40;  


// defines variables
long duration;
int distance[3];  //Stores the Distances into an array, make this similar to number of sensors.
int safetyDistance = 15; //in cm
 
 
void setup() {
for (int thisPin = 0; thisPin < sensorNumber; thisPin++)
  {
  pinMode(trigPins[thisPin],OUTPUT);  //Sets all echo pins as OUTPUT
  pinMode(echoPins[thisPin],INPUT);  // sets all trigger pins as INPUT
  }  
Serial.begin(9600); // Starts the serial communication
}
 
 
void loop() {
// Clears the trigPin
for (int thisPin = 0; thisPin < sensorNumber; thisPin++){
  digitalWrite(trigPins[thisPin], LOW);
  } 
  
delayMicroseconds(2);
 
// Sets the trigPin on HIGH state for 10 micro seconds
for (int thisPin = 0; thisPin < sensorNumber; thisPin++){
  digitalWrite(trigPins[thisPin], HIGH);
  }

delayMicroseconds(10);

for (int thisPin = 0; thisPin < sensorNumber; thisPin++){
  digitalWrite(trigPins[thisPin], LOW);
  
  // Reads the echoPin, returns the sound wave travel time in microseconds
  duration = pulseIn(echoPins[thisPin], HIGH);
  
  // Calculating the distance and storing them into the distace array in cm
  distance[thisPin] = duration*0.034/2;

  // check for safety
  if (distance[thisPin] <= safetyDistance)
  {
    digitalWrite(ledPin, HIGH);
  }
  else
  {
    digitalWrite(ledPin, LOW);
  }
  } 
  
Serial.println("Sensor 1 = " + String(distance[0]) + ", Sensor 2 = " + String(distance[1]) + ", Sensor 3 = " + String(distance[2]) );  //ADD SENSOR TILL 8 SENSORS WHEN USING MEGA
 
}
