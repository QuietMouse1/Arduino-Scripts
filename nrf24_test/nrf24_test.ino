#include <SPI.h>
#include "RF24.h"


char* msg; //hold message we are gonna send
RF24 radio(8,53); //CE , CSN
const uint64_t pipe = 1;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  radio.begin();
  radio.setPALevel(RF24_PA_MIN);
  Serial.println("Started!");
  radio.openWritingPipe(pipe);
  Serial.println("Opened!");
  msg = "hello! my name is james!";
}

void loop() {
  // put your main code here, to run repeatedly:
  radio.write(msg,strlen(msg)); //msg and length of msg
  Serial.println("SENT!");
  delay (2000); //transmit every 2 seconds
}
