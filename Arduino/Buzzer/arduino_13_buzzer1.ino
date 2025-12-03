// C++ code
//
int val;
int pin = 8;
int pinAn = A3;
float v;
void setup()
{
  pinMode(pin, OUTPUT);
  pinMode(pinAn,INPUT);
  Serial.begin(9600);
}

void loop()
{
  val = analogRead(pinAn);
  v = (5./1023.)*val;
  Serial.println(v);
  if(v>3){
    digitalWrite(pin,HIGH);
    val = analogRead(pinAn);
  	v = (5./1023.)*val;
  }
  digitalWrite(pin,LOW);
}