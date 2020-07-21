int two = 2;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.write(two);
  delay(3000);
  Serial.write("2");
  delay(3000);
}
