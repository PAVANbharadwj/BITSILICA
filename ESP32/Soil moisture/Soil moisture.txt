#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27,16,2);

void setup()
{
  Wire.begin(23, 22);
  Serial.begin(9600);
  lcd.init();
  lcd.backlight();
}

void loop()
{
  int16_t i = analogRead(34);
  String msg = i < 2165 ? "WET" : i > 3135 ? "DRY" : "OK";
  lcd.clear();
  lcd.print("Soil: ");
  lcd.print(msg);
  delay(500); 
}
