#include <Wire.h>

int sensorPin = A0;
int temperature = 0;

void setup() {
  Wire.begin(8);                
  Wire.onRequest(requestEvent); 
}

void loop() {
  int rawValue = analogRead(sensorPin);
  float voltage = (rawValue * 5.0) / 1023.0;
  temperature = voltage * 100;  // LM35 = 10mV/°C
  delay(200);
}

void requestEvent() {
  Wire.write((temperature >> 8) & 0xFF);
  Wire.write(temperature & 0xFF);
}
