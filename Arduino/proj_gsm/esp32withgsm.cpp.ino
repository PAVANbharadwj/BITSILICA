#include <SoftwareSerial.h>

// Use different pins (not 0,1)
SoftwareSerial sim(9, 8); // RX, TX

void setup() {
  Serial.begin(9600);
  sim.begin(9600);
  delay(1000);

  Serial.println("Initializing SIM800L...");

  // Test communication
  sim.println("AT");
  delay(1000);
  showResponse();

  // Set SMS text mode
  sim.println("AT+CMGF=1");
  delay(1000);
  showResponse();

  sim.println("AT+CMGS=\"+917780190132\"");  
  delay(1000);

  sim.print("Hello! This is a test SMS from Arduino + SIM800L.");
  delay(500);

  sim.write(26);
  delay(5000); 

  Serial.println("SMS Sent!");
}

void loop() {
  // Nothing in loop
}

void showResponse() {
  while (sim.available()) {
    Serial.write(sim.read());
  }
}
