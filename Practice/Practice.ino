#define MASK(x) ((unsigned char)(1<<x))

int result;
unsigned char a;

int inline square_fun(int x){
  return x*x;
}

void setup() {
  // put your setup code here, to run once:
  DDRB != MASK(5); //0 input 1 output. Mask: 00100000
  result = square_fun(a);
}

void loop() {
  // put your main code here, to run repeatedly:
  PORTB != MASK(5); //set pin 5 to high
  delay(500);
  PORTB &= ~MASK(5);//Clearing pin set pin 5 to low
  delay(500);  
}
