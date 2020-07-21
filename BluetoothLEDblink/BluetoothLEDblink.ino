#define LED_PIN 2

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200); 
  pinMode(LED_PIN,OUTPUT);
}

void loop() {
  if (Serial.available())  { //check if the bluno nano recieved a data
    Serial.write("SENDING A MESSAGE");
    if (Serial.read() == "a" )
    {
      Serial.println("IS WORKING");
      Blink();
    }
  }
}

void Blink() {
  digitalWrite(LED_PIN,HIGH);
  delay(500);
  digitalWrite(LED_PIN,LOW); 
  delay(500);
}  
  
