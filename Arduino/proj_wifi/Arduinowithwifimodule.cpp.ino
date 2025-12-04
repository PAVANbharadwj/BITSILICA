
#include <SoftwareSerial.h>
#include <WiFiEsp.h>

char ssid[] = "POCO C55";        
char pass[] = "123456789";    

SoftwareSerial espSerial(2, 3);
int status = WL_IDLE_STATUS;

WiFiEspServer server(80);

String clientMessage = "";
String serverReply = "Hello from Arduino!";

void setup() 
{
  Serial.begin(9600);
  espSerial.begin(9600); 
  WiFi.init(&espSerial);

  Serial.println("Connecting to WiFi...");
  while (status != WL_CONNECTED) {
    status = WiFi.begin(ssid, pass);
    Serial.print(".");
    delay(1000);
  }
  Serial.println("\nConnected to WiFi!");
  Serial.print("IP Address: ");
  Serial.println(WiFi.localIP());

  server.begin();  
  Serial.println("Server started. Access via browser!");
}

void loop() {
  WiFiEspClient client = server.available();
  
  if (client) {
    boolean currentLineIsBlank = true;
    String request = "";
    
    while (client.connected()) {
      if (client.available()) {
        char c = client.read();
        request += c;

        if (c == '\n' && currentLineIsBlank) {
          if (request.indexOf("GET /send?msg=") >= 0) {
            int start = request.indexOf("msg=") + 4;
            int end = request.indexOf(" ", start);
            clientMessage = request.substring(start, end);
            
            clientMessage.replace("+", " ");
            clientMessage.replace("%20", " ");

            Serial.println("Client says: " + clientMessage);

          }

          client.println("HTTP/1.1 200 OK");
          client.println("Content-Type: text/html");
          client.println("Connection: close");
          client.println();
          client.println("<html><body><h2>WiFi Chat</h2>");
          client.println("<form action='/send'><input name='msg' placeholder='Type message'><input type='submit' value='Send'></form>");
          client.println("<p><b>You:</b> " + clientMessage + "</p>");
          client.println("</body></html>");
          break;
        }

        if (c == '\n') currentLineIsBlank = true;
        else if (c != '\r') currentLineIsBlank = false;
      }
    }

    delay(1);
    client.stop(); 
  }

  if (Serial.available()) {
    serverReply = Serial.readStringUntil('\n');
    Serial.println("Reply updated: " + serverReply);
  }
}
