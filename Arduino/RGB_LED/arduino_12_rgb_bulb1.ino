// C++ code
//
int pinR = 2;
int pinG = 4;
int pinB = 3;
String msg = "Enter the color";
String mycolor;
void setup()
{
  pinMode(pinR, OUTPUT);
  pinMode(pinG, OUTPUT);
  pinMode(pinB, OUTPUT);
  Serial.begin(9600);
}

void loop()
{
  Serial.println(msg);
  while(Serial.available()==0){}
  mycolor = Serial.readString();
  
  if(mycolor=="red"){
    digitalWrite(pinR, HIGH);
    digitalWrite(pinG, LOW);
    digitalWrite(pinB, LOW);
  }
  if(mycolor=="green"){
    digitalWrite(pinR, LOW);
    digitalWrite(pinG, HIGH);
    digitalWrite(LED_BUILTIN, LOW);
  }
  if(mycolor=="blue"){
    digitalWrite(pinR, LOW);
    digitalWrite(pinG, LOW);
    digitalWrite(pinB, HIGH);
  }
  if(mycolor=="yellow"){
    analogWrite(pinR, 255);
    analogWrite(pinG, 255);
    analogWrite(pinB, 0);
  }
  if(mycolor=="aqua"){
    analogWrite(pinR, 0);
    analogWrite(pinG, 255);
    analogWrite(pinB, 255);
  }
  if(mycolor=="violet"){
    analogWrite(pinR, 255);
    analogWrite(pinG, 0);
    analogWrite(pinB, 255);
  }
}