#include <IRremote.h>

int IRpin = 9;
String myCom;

int rPin = 6;
int gPin = 10;
int bPin = 5;

int rBright = 255;
int gBright = 255;
int bBright = 255;

float dFact = 1;

void setup() {
  Serial.begin(9600);
  IrReceiver.begin(IRpin, ENABLE_LED_FEEDBACK);

  pinMode(rPin, OUTPUT);
  pinMode(gPin, OUTPUT);
  pinMode(bPin, OUTPUT);
}

void loop() {
  if (IrReceiver.decode()) {
    unsigned long cmd = IrReceiver.decodedIRData.decodedRawData;
    myCom = "";

    if (cmd == 0xFF00BF00) { myCom = "pwr"; }       
    else if (cmd == 0xFE01BF00) { myCom = "v+"; }   
    else if (cmd == 0xFD02BF00) { myCom = "stop"; } 
    else if (cmd == 0xFB04BF00) { myCom = "bw"; }  
    else if (cmd == 0xFA05BF00) { myCom = "pause"; }
    else if (cmd == 0xF906BF00) { myCom = "fw"; }  
    else if (cmd == 0xF708BF00) { myCom = "dn"; }   
    else if (cmd == 0xF609BF00) { myCom = "v-"; }
    else if (cmd == 0xF50ABF00) { myCom = "up"; }   
    else if (cmd == 0xF30CBF00) { myCom = "0"; }
    else if (cmd == 0xF20DBF00) { myCom = "eq"; }
    else if (cmd == 0xF10EBF00) { myCom = "rept"; }
    else if (cmd == 0xEF10BF00) { myCom = "1"; }
    else if (cmd == 0xEE11BF00) { myCom = "2"; }
    else if (cmd == 0xED12BF00) { myCom = "3"; }
    else if (cmd == 0xEB14BF00) { myCom = "4"; }
    else if (cmd == 0xEA15BF00) { myCom = "5"; }
    else if (cmd == 0xE916BF00) { myCom = "6"; }
    else if (cmd == 0xE718BF00) { myCom = "7"; }
    else if (cmd == 0xE619BF00) { myCom = "8"; }
    else if (cmd == 0xE51ABF00) { myCom = "9"; }

    if (myCom == "pwr") {
      rBright = 255; gBright = 255; bBright = 255; dFact = 1;
    }
    if (myCom == "stop") {
      rBright = 0; gBright = 0; bBright = 0; dFact = 0;
    }
    if (myCom == "0") { rBright = 255; gBright = 255; bBright = 255; }
    if (myCom == "1") { rBright = 255; gBright = 0;   bBright = 0;   }  
    if (myCom == "2") { rBright = 0;   gBright = 255; bBright = 0;   }   
    if (myCom == "3") { rBright = 0;   gBright = 0;   bBright = 255; }   
    if (myCom == "4") { rBright = 0;   gBright = 255; bBright = 255; }   
    if (myCom == "5") { rBright = 255; gBright = 0;   bBright = 150; }   
    if (myCom == "6") { rBright = 255; gBright = 255; bBright = 0;   }   

    if (myCom == "dn") {
      dFact *= 0.75;
    }

    if (myCom == "up") {
      dFact *= 1.3;
      if (dFact > 1) dFact = 1;
    }

    analogWrite(rPin, rBright * dFact);
    analogWrite(gPin, gBright * dFact);
    analogWrite(bPin, bBright * dFact);

    if (myCom != "") {
      Serial.println(myCom);
    }

    IrReceiver.resume();  
  }
}
