  int button = 8;
  int led = 7;
  
  int ledState = HIGH;
  int buttonCurrent;
  int buttonPrevious = LOW;

void setup() 
{
  pinMode(button, INPUT);
  pinMode(led, OUTPUT);
}

void loop() 
{
  buttonCurrent = digitalRead(button);

  if (buttonCurrent == HIGH && buttonPrevious == LOW)
  {
    if (ledState == HIGH)
    {
      ledState = LOW;
    }
    else
   {
      ledState = HIGH;
   }
  }

  digitalWrite(led, ledState);
  buttonPrevious = buttonCurrent;
}
