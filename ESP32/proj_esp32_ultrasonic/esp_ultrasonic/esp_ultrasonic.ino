#include <SoftwareSerial.h>

SoftwareSerial esp(2, 3);

void setup()
{
  Serial.begin(115200);
  esp.begin(115200);

  Serial.println("ESP Ready");
}

void loop()
{
  if (esp.available())
  {
    Serial.write(esp.read());
  }

  if (Serial.available())
  {
    esp.write(Serial.read());
  }
}