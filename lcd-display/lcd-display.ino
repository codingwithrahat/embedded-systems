#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup() {
  lcd.init();
  lcd.backlight();
}

void loop() {
  
  lcd.clear();
  delay(2000);
  
  lcd.setCursor(0, 0);
  lcd.print("Coding With");
  
  lcd.setCursor(11, 1);
  lcd.print("Rahat");
  
  delay(2000);
    

}
