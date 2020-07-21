/* 
The code below are for multiple GPY20A IR sensors. The pins are stored in a data array.

IMPT NOTES-
The distance value depends on the data sheet given (if any!) and it could be measured manually using analogRead (read voltage value from sensor). 255 = 5v , 0 = 0v with a linear relationship.

*/

// Sharp IR GP2Y0A41SK0F Distance Test
// http://tinkcore.com/sharp-ir-gp2y0a41-skf/
// copied from https://www.instructables.com/id/How-to-Use-the-Sharp-IR-Sensor-GP2Y0A41SK0F-Arduin/

int sensorPins[] =  {A0}; // CHANGE THIS WHEN USING MEGA  // Sharp IR GP2Y0A41SK0F (4-30cm, analog) CM
int sensorNumber = 1;
int distanceValue[1];  // CHANGE THIS WHEN USING MEGA 
void setup() {
  Serial.begin(9600); // start the serial port
  for( int thisSensor = 0; thisSensor < sensorNumber ; thisSensor++)
  {
    pinMode(sensorPins[thisSensor],INPUT);
  }
}

void loop() {
  // 5
  for (int i = 0 ; i <sensorNumber ; i++)
  {
  float volts = analogRead(sensorPins[i])*0.0048828125;  // value from sensor * (5/1024)
  distanceValue[i] = 13*pow(volts, -1); // worked out from datasheet graph
  }
  delay(1000); // slow down serial port
  Serial.println("Sensor 1 = " + String(distanceValue[0])); // + "Sensor 2 = " + String(distanceValue[1]));
}
