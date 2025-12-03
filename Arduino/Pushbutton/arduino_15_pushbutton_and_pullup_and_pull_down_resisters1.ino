// C++ code
//
int ledpin = 8;
int pinb = 5;
int val;
void setup()
{
  pinMode(ledpin, OUTPUT);
  pinMode(pinb,INPUT);
  Serial.begin(9600);
}

void loop()
{
  val = digitalRead(pinb);
  Serial.println(val);
  if(val==1){
    digitalWrite(ledpin,LOW);
  }
  if(val==0){
    digitalWrite(ledpin,HIGH);
  }
}