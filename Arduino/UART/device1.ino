#include <LiquidCrystal.h>

LiquidCrystal lcd(2,3,4,5,6,7);
byte receivedTemp = 0;

void setup() {
  lcd.begin(16,2);
  lcd.print("Master LCD");
  Serial.begin(9600);
}

void loop() {
  if(Serial.available() > 0) {
    receivedTemp = Serial.read(); 
    lcd.setCursor(0,1);
    lcd.print("Temp: ");
    lcd.print(receivedTemp);
    lcd.print(" C   ");
  }
}
