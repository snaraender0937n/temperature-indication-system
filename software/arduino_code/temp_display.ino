// Temperature indication using relay input and LCD (I2C)

#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

int inputPin = 2;  // Relay output connected to pin 2

void setup() {
  pinMode(inputPin, INPUT);

  lcd.init();
  lcd.backlight();

  lcd.setCursor(0, 0);
  lcd.print("System Starting");
  delay(2000);
  lcd.clear();
}

void loop() {

  int state = digitalRead(inputPin); // Read relay status

  lcd.clear();

  if (state == HIGH) {
    lcd.setCursor(0, 0);
    lcd.print("TEMP HIGH");

    lcd.setCursor(0, 1);
    lcd.print("FAN ON");   // Just indication
  } 
  else {
    lcd.setCursor(0, 0);
    lcd.print("TEMP NORMAL");

    lcd.setCursor(0, 1);
    lcd.print("FAN OFF");  // Just indication
  }

  delay(500);
}
