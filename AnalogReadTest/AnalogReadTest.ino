int vol;
const int pinAdc = A1;
void setup() {
  // put your setup code here, to run once:
Serial.begin (9600);

}

void loop(){
  vol = analogRead(A1);
  Serial.println(vol);
}
