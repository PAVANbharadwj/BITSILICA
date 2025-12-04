/*void setup() {
  pinMode(13,OUTPUT);
}

void loop() {
  digitalWrite(13,HIGH);
  delay(20);
  digitalWrite(13,LOW);
  delay(20);
}*/

int trigPin=12;
int echoPin=11;
int pingTravelTime;
float pingTravelDistance;
float distanceToTarget;
int dt=50;
void setup() 
{
  pinMode(trigPin,OUTPUT);
  pinMode(echoPin,INPUT);
  pinMode(13,OUTPUT);
  Serial.begin(9600);
}
void loop() 
{
  digitalWrite(trigPin,LOW);
  delayMicroseconds(10);
  digitalWrite(trigPin,HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin,LOW);
  pingTravelTime=pulseIn(echoPin,HIGH);
  delay(50);
  pingTravelDistance=(pingTravelTime*765.*5280.*12)/(3600.*1000000);
  distanceToTarget=pingTravelDistance/2;
  Serial.print("Distance to target is ");
  Serial.print(distanceToTarget);
  Serial.println("inch.");
  delay(dt);
  if (distanceToTarget>=20)
  {
    digitalWrite(13,HIGH);
    delay(500);
    digitalWrite(13,LOW);
    delay(500);
  }
  else if (distanceToTarget>=10&&distanceToTarget<20)
  {
    digitalWrite(13,HIGH);
    delay(250);
    digitalWrite(13,LOW);
    delay(250);
  }
  else if (distanceToTarget>=5&&distanceToTarget<10)
  {
    digitalWrite(13,HIGH);
    delay(100);
    digitalWrite(13,LOW);
    delay(100);
  }
  else if (distanceToTarget<5)
  {
    digitalWrite(13,HIGH);
    delay(10);
    digitalWrite(13,LOW);
    delay(10);
  }
}

