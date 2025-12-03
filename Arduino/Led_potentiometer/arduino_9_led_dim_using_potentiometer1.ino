// C++ code
//
int potpin = A3;
int LPIN = 6;
int potval;
float V;


void setup()
{
  pinMode(potpin, INPUT);
  pinMode(LPIN,OUTPUT);
  Serial.begin(9600);
}

void loop()
{
  potval = analogRead(potpin);
  V = (255./1023.)*potval;
  analogWrite(LPIN,V);
  
  
}