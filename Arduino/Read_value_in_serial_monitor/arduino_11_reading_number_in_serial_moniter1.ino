// C++ code
//
int PIN = 12;
String msg = "How many blinks";
int val;
void setup()
{
  pinMode(PIN, OUTPUT);
  Serial.begin(9600);
}

void loop()
{
  Serial.println(msg);
  while(Serial.available()==0){}
  val = Serial.parseInt();
  for(int i=0;i<val;i++){
    digitalWrite(PIN, HIGH);
    delay(500);
    digitalWrite(PIN, LOW);
    delay(500); 
  }
}