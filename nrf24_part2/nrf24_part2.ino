#include <SPI.h>
#include "RF24.h"

const int maxMagLength = 64;
char mag(maxMagLength);

RF24 radio(8,53); //CE , CSN
const uint64_t pipe = 1;


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  radio.begin();
  radio.setPALevel(RF24_PA_MIN);
  Serial.println("Started!");
  radio.openReadingPipe(1,pipe);
  Serial.println("Opened!");
  radio.startListening();
  Serial.println("Listening...");
}

void loop() {
  // put your main code here, to run repeatedly:
  if (radio.available()){
    Serial.println("avaible!");
    radio.read(mag,maxMagLength-1);
    Serial.println("Read!" + String(mag));
  }else {
    Serial.println("Not avaible");
  }
  delay (2500);
  Serial.println("Wait...");
  }
