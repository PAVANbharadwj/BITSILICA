// C++ code
//
int pin = A0;
int lightval;
void setup()
{
  pinMode(pin, INPUT);
  Serial.begin(9600);
}

void loop()
{
  lightval = analogRead(pin);
  Serial.println(lightval);
  delay(250);
  
}