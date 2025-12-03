// C++ code
//
int ledpin = 8;
int dit = 400;
int dah = 800;
void setup()
{
  pinMode(ledpin, OUTPUT);
}

void loop()
{
  digitalWrite(ledpin, HIGH);
  delay(dit); 
  digitalWrite(ledpin, LOW);
  delay(dit);
  
  digitalWrite(ledpin, HIGH);
  delay(dit); 
  digitalWrite(ledpin, LOW);
  delay(dit);
  
  digitalWrite(ledpin, HIGH);
  delay(dit); 
  digitalWrite(ledpin, LOW);
  delay(dit);
  
  delay(1000);
  
  digitalWrite(ledpin, HIGH);
  delay(dah); 
  digitalWrite(ledpin, LOW);
  delay(dah);
  
  digitalWrite(ledpin, HIGH);
  delay(dah); 
  digitalWrite(ledpin, LOW);
  delay(dah);
  
  digitalWrite(ledpin, HIGH);
  delay(dah); 
  digitalWrite(ledpin, LOW);
  delay(dah);
  
  delay(1000);
  
  digitalWrite(ledpin, HIGH);
  delay(dit); 
  digitalWrite(ledpin, LOW);
  delay(dit);
  
  digitalWrite(ledpin, HIGH);
  delay(dit); 
  digitalWrite(ledpin, LOW);
  delay(dit);
  
  digitalWrite(ledpin, HIGH);
  delay(dit); 
  digitalWrite(ledpin, LOW);
  delay(dit);
  
  while(true);
  
}