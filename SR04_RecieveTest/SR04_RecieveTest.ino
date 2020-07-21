// Reciever test

#include <SPI.h>
#include <NewPing.h>

// HC-SR04
const byte ECHO_PIN = 5;
const byte TRIGGER_PIN = 4;
const unsigned int MAX_DISTANCE = 500; // 5 meters = approx 16 ft

// other
byte ledPin = 9;

// objects
NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE); // NewPing setup of pins and maximum distance.

//***********************************
void setup() {
  Serial.begin(9600);
  pinMode(ledPin, OUTPUT);
}

//***********************************
void loop() {

  Serial.println(F("Now sending"));
  byte dist = sonar.ping_cm();
  if (dist == 0)
  {
    Serial.println("No Echo Recieved"); 
  }
  else{
  Serial.println(String(dist));
  }
  blinkOnce(100);

  delay(1000 );

} // Loop

//***********************************
void blinkOnce(int dur) {
  digitalWrite(ledPin, HIGH);
  delay(dur);
  digitalWrite(ledPin, LOW);
  delay(dur);
}
