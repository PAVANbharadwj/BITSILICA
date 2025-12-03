
int PIN = A2;
int PINR = 9;
int PINY = 10;
int PING = 11;
int readVal;
float V;


void setup()
{
  pinMode(PIN, INPUT);
  pinMode(PING, OUTPUT);
  pinMode(PINR, OUTPUT);
  pinMode(PINY, OUTPUT);
  Serial.begin(9600);
  
}

void loop()
{
  readVal = analogRead(PIN);
  V = (5./1023.)*readVal;
  Serial.print("Potentiometer Voltage is ");
  Serial.println(V);
  if(V>4.0){
    digitalWrite(PINR,HIGH);
  }
  if(V<4.0){
    digitalWrite(PINR,LOW);
  }
  if(V>2.0 && V<=4.0){
    digitalWrite(PINY,HIGH);
  }
  if(V<2.0 || V>4.0){
    digitalWrite(PINY,LOW);
  }
  if(V>0 && V<=2.0){
    digitalWrite(PING,HIGH);
  }
  if(V>2.0){
    digitalWrite(PING,LOW);
  }
  
  delay(500);
}