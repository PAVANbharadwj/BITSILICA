#include <Wire.h>

int ldrPin = A0;
int lightVal = 0;

void setup() {
  Wire.begin(9);
  Wire.onRequest(requestEvent);
}

void loop() {
  lightVal = analogRead(ldrPin); 
  delay(200);
}

void requestEvent() {
  Wire.write((lightVal >> 8) & 0xFF);
  Wire.write(lightVal & 0xFF);
}
