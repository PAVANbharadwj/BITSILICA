// C++ code
//
int pinb1 = 9;
int pinb2 = 8;
int ledpin = 3;
int val1;
int val2;
int led=0;
int buzz = 2;
void setup()
{
  pinMode(pinb1, INPUT);
  pinMode(pinb2,INPUT);
  pinMode(ledpin,OUTPUT);
  pinMode(buzz,OUTPUT);
  Serial.begin(9600);
}

void loop()
{
  val1=digitalRead(pinb1);
  Serial.print(val1);
  Serial.print(" ");
  val2=digitalRead(pinb2);
  Serial.println(val2);
  delay(250);
  if(val1==0){
    led=led+50;
  }
  if(val2==0){
    led=led-50;
  }
  if(led>255){
    led=255;
    digitalWrite(buzz,HIGH);
    delay(100);
    digitalWrite(buzz,LOW);
  }
  if(led<0){
    led=0;
    digitalWrite(buzz,HIGH);
    delay(100);
    digitalWrite(buzz,LOW);
  }
  analogWrite(ledpin,led);
}