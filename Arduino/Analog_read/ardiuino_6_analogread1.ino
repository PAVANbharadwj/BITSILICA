// C++ code
//
int Pin=A3;
int readval;
float v=0;

void setup()
{
  pinMode(Pin, INPUT);
  Serial.begin(9600);
}

void loop()
{
  readval = analogRead(Pin);
  v = (5./1023.)*readval;
  Serial.println(v);
  delay(500);
}