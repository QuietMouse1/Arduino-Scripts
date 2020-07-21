// TX test

#include <SPI.h>
#include "RF24.h"
#include <NewPing.h>

//RF
const boolean radioNumber = 1; // TX=1
const byte enablePin = 7; // CE
const byte selectPin = 8; // CS
const byte addresses[][6] = {
  "1Node", "2Node"};

// HC-SR04
const byte ECHO_PIN = A5;
const byte TRIGGER_PIN = A4;
const unsigned int MAX_DISTANCE = 500; // 5 meters = approx 16 ft

// other
byte timePin = 2;
byte ledPin = 22;
unsigned long sendTime;

// objects
RF24 radio(enablePin, selectPin);  //Set up nRF24L01 radio on SPI bus plus CE and CS pins
NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE); // NewPing setup of pins and maximum distance.

//***********************************
void setup() {
  Serial.begin(9600);
  Serial.println(F("TX"));

  pinMode(timePin, OUTPUT);

  pinMode(ledPin, OUTPUT);
  blinkOnce(1500);

  radio.begin();
  radio.setChannel(108);
  
  if (radioNumber) {
    radio.openWritingPipe(addresses[1]);
    radio.openReadingPipe(1, addresses[0]);
  } 
  else {
    radio.openWritingPipe(addresses[0]);
    radio.openReadingPipe(1, addresses[1]);
  }

  radio.enableDynamicAck(); // oddly, this is req'd for "no ACK" writes
  radio.stopListening();
}

//***********************************
void loop() {

  Serial.println(F("Now sending"));

  byte rWrite = radio.write( &sendTime, sizeof(unsigned long), true );  // "true" = no ACK (for future multicast)
  digitalWrite(timePin, HIGH); // pulls interrupt pin at RX uC high
  byte dist = sonar.ping_cm();
  blinkOnce(100);
  digitalWrite(timePin, LOW);

  delay(4000);

} // Loop

//***********************************
void blinkOnce(int dur) {
  digitalWrite(ledPin, HIGH);
  delay(dur);
  digitalWrite(ledPin, LOW);
  delay(dur);
}
