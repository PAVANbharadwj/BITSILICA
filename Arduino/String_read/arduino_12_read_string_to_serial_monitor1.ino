// C++ code
//
int pinR = 2;
int pinG = 3;
int pinB = 4;
String MyColor;

void setup()
{
  pinMode(pinR, OUTPUT);
  pinMode(pinG, OUTPUT);
  pinMode(pinB, OUTPUT);
  Serial.begin(9600);
}

void loop()
{
  Serial.println("Enter the color:");
  while(Serial.available()==0){}
  MyColor = Serial.readString();
  if(MyColor=="red"){
    digitalWrite(pinR,HIGH);
    digitalWrite(pinG,LOW);
    digitalWrite(pinB,LOW);
    
  }
  if(MyColor=="green"){
    digitalWrite(pinR,LOW);
    digitalWrite(pinG,HIGH);
    digitalWrite(pinB,LOW);
    
  }
  if(MyColor=="blue"){
    digitalWrite(pinR,LOW);
    digitalWrite(pinG,LOW);
    digitalWrite(pinB,HIGH);
    
  }
}