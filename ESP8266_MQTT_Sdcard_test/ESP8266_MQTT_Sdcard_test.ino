// ESP8266 with SD card reader 
#include <Wire.h>
#include <SPI.h>
#include <SD.h>
#include <SoftwareSerial.h>
#include <PubSubClient.h>
#include <ESP8266WiFi.h>
SoftwareSerial mySerial(5,4); //rx,tx

byte chipSelect = 15;

File testFile;
File dataFile;

String dataOut = "" ; 

// Change the credentials below, so your ESP8266 connects to your router
const char* ssid = "REPLACE_WITH_YOUR_SSID";
const char* password = "REPLACE_WITH_YOUR_PASSWORD";
const char* mqtt_server = "REPLACE_WITH_YOUR_RPI_IP_ADDRESS";
// Initializes the espClient. You should change the espClient name if you have multiple ESPs running in your home automation system
WiFiClient espClient;
PubSubClient client(espClient);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  mySerial.begin(9600);
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

  setup_wifi();
  client.setServer(mqtt_server, 1883);
  client.setCallback(callback);
}
void loop() {
  if (!client.connected()) {
    reconnect();
  }
  if(!client.loop())
    client.connect("ESP8266Client");

  while(mySerial.available()){
    char incomingByte = mySerial.read();
    if (incomingByte != '\n'){
      dataOut += incomingByte;
      //Serial.println(dataOut);
     // Publishes Temperature and Humidity values
      //client.publish("room/temperature", temperatureTemp);
      //client.publish("room/humidity", humidityTemp);
    }
    else{
      Serial.println(dataOut);
      dataFile = SD.open("Data.csv",FILE_WRITE);
      dataFile.println(dataOut);
      dataFile.close();
      dataOut ="";
    }
  }
}
