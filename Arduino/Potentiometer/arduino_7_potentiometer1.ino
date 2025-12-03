// C++ code
//
int PIN = A2;
int readVal;
float V;


void setup()
{
  pinMode(PIN, INPUT);
  Serial.begin(9600);
}

void loop()
{
  readVal = analogRead(PIN);
  V = (5./1023.)*readVal;
  Serial.println(V);
  delay(500);
}