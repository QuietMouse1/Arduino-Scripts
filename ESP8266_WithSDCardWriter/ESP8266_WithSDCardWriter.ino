// ESP8266 with SD card reader 
#include <Wire.h>
#include <SPI.h>
#include <SD.h>
byte chipSelect = 15;

File testFile;
File dataFile;

byte incomingByte = 0;

void setup() {
  Serial.begin(9600);
  Serial.print("Initializing SD card...");
  if (!SD.begin(chipSelect)) {
    Serial.println("initialization failed!");
    return;
  }
  Serial.println("initialization done.");
  dataFile = SD.open("Data.csv",FILE_WRITE);
  if(dataFile){
  dataFile.println(String("Frequency,") + String("Magnitude,") + String("Impedance"));
  dataFile.close();
  Serial.println("done writing.");
  }
}

void loop() {
  // put your main code here, to run repeatedly:
  if (Serial.available())
  {
    incomingByte = Serial.read();
    dataFile = SD.open("Data.csv",FILE_WRITE);
    dataFile.println(incomingByte,DEC);
    dataFile.close();
    Serial.println(incomingByte);
  }
}
