#include <Stepper.h>
#include <LiquidCrystal.h>

int button = 8;
int led = 7;

int ledState = LOW;
int buttonCurrent;
int buttonPrevious = HIGH;

int Contrast=120;
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

#define STEPS 16
Stepper stepper (STEPS, 13, 10, 1, 0);
int previous = 0;

void setup() 
{
  analogWrite(6,Contrast);
  lcd.begin(16,2);
  Serial.begin(9600);
  
  pinMode(button, INPUT);
  pinMode(led, OUTPUT);

  stepper.setSpeed(30);
}

void loop() 
{
  int sensorValue = analogRead(A0);
  float valvePosition = ((50/4.85) * sensorValue);
  Serial.println(valvePosition);
  
  buttonCurrent = digitalRead(button);

  if (buttonCurrent == HIGH && buttonPrevious == LOW)
  {
    if (ledState == HIGH)
    {
      ledState = LOW;
      lcd.setCursor(6,0);
      lcd.print("OFF");
      delay(1000);
      lcd.clear();
    }
    else
   {
      ledState = HIGH;
      lcd.setCursor(6,0);
      lcd.print("ON");
      delay(1000);
      lcd.clear();
   }
  }

  digitalWrite(led, ledState);
  buttonPrevious = buttonCurrent;

  if (ledState == HIGH)
  {
    stepper.step(sensorValue - previous);
    previous = sensorValue;
    lcd.setCursor(0,0);
    lcd.print("Valve position = ");
    lcd.print(valvePosition);
    delay(200);
  }
}
