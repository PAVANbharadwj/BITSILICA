#include <HardwareSerial.h>

HardwareSerial gsm(2);  // UART2

void setup() {
  Serial.begin(115200);
  gsm.begin(9600, SERIAL_8N1, 16, 17);  // RX=16, TX=17

  Serial.println("Initializing GSM...");
  delay(2000);

  sendAT("AT");          // Check module
  sendAT("ATE0");        // Echo off
  sendAT("AT+CMGF=1");   // SMS text mode

  // Replace with your phone number
  sendSMS("+91XXXXXXXXXX", "Hello from ESP32 + SIM800L!");
}

void loop() {}

void sendSMS(String number, String message) {
  gsm.print("AT+CMGS=\"");
  gsm.print(number);
  gsm.println("\"");
  delay(500);

  gsm.println(message);
  delay(500);

  gsm.write(26); // CTRL+Z to send
  delay(3000);

  Serial.println("SMS Sent");
}

void sendAT(String cmd) {
  gsm.println(cmd);
  delay(500);
  while (gsm.available()) {
    Serial.println(gsm.readString());
  }
}
