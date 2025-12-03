// C++ code
//
int PINR = 6;
int PINY = 9;

void setup()
{
  pinMode(PINR, OUTPUT);
  pinMode(PINY,OUTPUT);
  Serial.begin(9600);
}

void loop()
{
  for(int i=1;i<=3;i++){
    digitalWrite(PINR, HIGH);
    delay(200);
    digitalWrite(PINR, LOW);
    delay(200);
  }
  
  for(int i=1;i<=5;i++){
    digitalWrite(PINY, HIGH);
    delay(200);
    digitalWrite(PINY, LOW);
    delay(200);
  }  
}