#include <LiquidCrystal.h>

int Contrast=120;
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

void setup() {
  // put your setup code here, to run once:

  analogWrite(6,Contrast);
  lcd.begin(16,2);
  Serial.begin(9600);
  
}

void loop() {
  // put your main code here, to run repeatedly:
 ;
  
  int sensorValue = analogRead(A0);
  float voltage= sensorValue * (5.0 / 1023.0);

  Serial.println(voltage);

  if (voltage > 3.638)
  {
    lcd.setCursor(0,0);
    lcd.print("Valves 50% Open");
    delay(1000);
    lcd.clear();
    delay(100);
  }

  if (voltage > 1.213 && voltage < 3.638)
  {
    lcd.setCursor(0,0);
    lcd.print("Valves 100% Open");
    delay(1000);
    lcd.clear();
    delay(100);
  }
  
  if (voltage < 1.213)
  {
    lcd.setCursor(0,0);
    lcd.print("Valves Closed");
    delay(1000);
    lcd.clear();
    delay(100);
  }
  
}
