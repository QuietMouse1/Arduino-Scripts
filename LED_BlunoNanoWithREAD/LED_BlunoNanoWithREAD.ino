void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);  //initial the Serial
  pinMode(2,OUTPUT);
  
}

void loop() {
  
  if (Serial.available())  { //check if blunonano is connected  to a device
    
    Serial.write(Serial.read());//send what has been received by the bluno nano
    if (Serial.read() == "ON") 
    {
      Blink();
      Serial.println("Recieved");
    }
    else if (Serial.read() == "OFF")
    {
      
    }

    Serial.println(Serial.read());   //print line feed character
  }
}

void Blink() {
  digitalWrite(2,HIGH);
  delay(500);
  digitalWrite(2,LOW);
  delay(500);  
}
