#include <LiquidCrystal.h>
int rs=7;
int en=8;
int d4=9;
int d5=10;
int d6=11;
int d7=12;
int buttonPin=A0;
int buttonVal;
LiquidCrystal lcd(rs,en,d4,d5,d6,d7);
 
int trigPin=2;
int echoPin=3;
int pingTravelTime;
float pingTravelDistance;
float distanceToTarget;
int dt=5000;
void setup() {
lcd.begin(16,2);
pinMode(trigPin,OUTPUT);
pinMode(echoPin,INPUT);
pinMode(buttonPin,INPUT);
digitalWrite(buttonPin,HIGH);
Serial.begin(9600);
 
}
 
void loop() {
lcd.setCursor(0,0);
lcd.print("Place the Target");
lcd.setCursor(0,1);
lcd.print("Press to Measure");
buttonVal=digitalRead(buttonPin);
while (buttonVal==1){
  buttonVal=digitalRead(buttonPin);
}
 
digitalWrite(trigPin,LOW);
delayMicroseconds(10);
digitalWrite(trigPin,HIGH);
delayMicroseconds(10);
digitalWrite(trigPin,LOW);
pingTravelTime=pulseIn(echoPin,HIGH);
delay(25);
pingTravelDistance=(pingTravelTime*765.*5280.*12)/(3600.*1000000);
distanceToTarget=pingTravelDistance/2;
Serial.print("Distance to Target is: ");
Serial.print(distanceToTarget);
Serial.println(" in.");
lcd.clear();
lcd.setCursor(0,0);
lcd.print("Target Distance");
lcd.setCursor(0,1);
lcd.print(distanceToTarget);
lcd.print(" Inches");
delay(dt);
 
 
}