// C++ code
//
int pinm = 5;
int potpin = A0;
int val;
void setup()
{
  pinMode(pinm, OUTPUT);
  pinMode(potpin,INPUT);
  Serial.begin(9600);
}

void loop()
{
  val = analogRead(potpin);
  analogWrite(pinm,val);
  delay(100);
}