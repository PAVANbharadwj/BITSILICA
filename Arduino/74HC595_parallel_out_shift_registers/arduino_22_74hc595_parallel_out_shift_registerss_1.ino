// C++ code
//
int latchpin=11;
int clockpin=9;
int datapin=12;

byte LED1s=0b11111110;


void setup()
{
  pinMode(latchpin, OUTPUT);
  pinMode(clockpin, OUTPUT);
  pinMode(datapin, OUTPUT);
  Serial.begin(9600);
}

void loop()
{
  digitalWrite(latchpin, LOW);
  shiftOut(datapin,clockpin,LSBFIRST,LED1s);
  digitalWrite(latchpin,HIGH);
  delay(500);
  LED1s = LED1s/128+LED1s*2;
}