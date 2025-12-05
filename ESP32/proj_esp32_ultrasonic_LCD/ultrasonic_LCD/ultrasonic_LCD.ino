#include <LiquidCrystal.h>

#define TRIG 5
#define ECHO 18

// RS, EN, D4, D5, D6, D7
LiquidCrystal lcd(14, 15, 19, 23, 25, 26);

void setup() {
  Serial.begin(115200);

  pinMode(TRIG, OUTPUT);
  pinMode(ECHO, INPUT);

  lcd.begin(16, 2);
  lcd.print("Ultrasonic");
  delay(1000);
}

void loop() {
  long duration;
  float distance;

  digitalWrite(TRIG, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG, LOW);

  duration = pulseIn(ECHO, HIGH);
  distance = duration * 0.034 / 2;  // cm

  Serial.print("Distance: ");
  Serial.println(distance);

  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Distance:");
  lcd.setCursor(0, 1);
  lcd.print(distance);
  lcd.print(" cm");

  delay(300);
}
