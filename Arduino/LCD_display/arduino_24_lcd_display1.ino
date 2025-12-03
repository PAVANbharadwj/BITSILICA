// C++ code
//
#include<LiquidCrystal.h>
int rs=7;
int en=8;
int d4=9;
int d5=10;
int d6=11;
int d7=12;
int num1;
int num2;
int ans;
LiquidCrystal lcd(rs,en,d4,d5,d6,d7);
void setup()
{
  pinMode(LED_BUILTIN, OUTPUT);
  lcd.begin(16,2);
  Serial.begin(9600);
}

void loop()
{
  lcd.setCursor(0,0);
  lcd.print("Enter the First Number");
  while(Serial.available()==0){}
  num1=Serial.parseInt();
  lcd.print(num1);
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Enter the second Number");
  while(Serial.available()==0){}
  num2=Serial.parseInt();
  lcd.print(num2);
  ans=num1+num2;
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print(ans);
  delay(1000);
  lcd.clear();
}