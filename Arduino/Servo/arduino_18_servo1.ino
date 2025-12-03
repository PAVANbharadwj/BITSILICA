// C++ code
//
#include<Servo.h>
int servopin = 9;
int servopos;
Servo myServo;

void setup()
{
  Serial.begin(9600);
  myServo.attach(servopin);
}

void loop()
{
  Serial.println("Enter the angle");
  while(Serial.available()==0){}
  servopos = Serial.parseInt();
  myServo.write(servopos);
}