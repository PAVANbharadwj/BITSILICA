const int tempPin = A0;

void setup() {
  Serial.begin(9600);
}

void loop() {
  int tempReading = analogRead(tempPin);
  float voltage = tempReading * (5.0 / 1023.0);
  float temperatureC = voltage * 100.0; // LM35 conversion

  Serial.write((byte)temperatureC); // send integer part to Master
  delay(1000); // send every second
}
