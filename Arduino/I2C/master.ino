#include <Wire.h>
#include <LiquidCrystal.h>

LiquidCrystal lcd(7, 8, 9, 10, 11, 12); 

const int button1 = 2;
const int button2 = 3;

void setup() {
  Wire.begin(); 
  Serial.begin(9600);

  pinMode(button1, INPUT_PULLUP);
  pinMode(button2, INPUT_PULLUP);

  lcd.begin(16, 2);
  lcd.print("I2C Sensor Demo");
  delay(1000);
  lcd.clear();
}

void loop() {
  if (digitalRead(button1) == LOW) {
    Wire.requestFrom(8, 2); 
    if (Wire.available() >= 2) {
      int temp = (Wire.read() << 8) | Wire.read();
      Serial.print("Temp: ");
      Serial.print(temp);
      Serial.println(" C");

      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("Temperature:");
      lcd.setCursor(0, 1);
      lcd.print(temp);
      lcd.print(" C");
    }
    delay(500);
  }

  if (digitalRead(button2) == LOW) {
    Wire.requestFrom(9, 2); // 2 bytes (int)
    if (Wire.available() >= 2) {
      int lightVal = (Wire.read() << 8) | Wire.read();
      Serial.print("Light: ");
      Serial.println(lightVal);

      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("Light Value:");
      lcd.setCursor(0, 1);
      lcd.print(lightVal);
    }
    delay(500);
  }
}
