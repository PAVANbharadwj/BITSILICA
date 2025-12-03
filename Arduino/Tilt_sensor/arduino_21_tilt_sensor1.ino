// C++ code
//
int pinT = 2;
int val;
int pinR = 3;
int pinG = 4;

void setup()
{
  pinMode(pinT, OUTPUT);
  pinMode(pinR,OUTPUT);
  pinMode(pinG,OUTPUT);
  digitalWrite(pinT, HIGH);
  Serial.begin(9600);
}

void loop()
{
  val = digitalRead(pinT);
  Serial.println(val);
  if(val==0){
    digitalWrite(pinG,HIGH);
    digitalWrite(pinR,LOW);
  }
  if(val==1){
    digitalWrite(pinG,LOW);
    digitalWrite(pinR,HIGH);
  }
}