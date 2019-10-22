#include <FastLED.h>
#include <pixeltypes.h>

// WS2812B (neopixel) LED information
#define NUM_LEDS 56
#define DATA_PIN 5

// potentiometer input pin
const int potInput = A2;

// array size for input smoothing
const int numReadings = 10;

int readings[numReadings];
int readIndex = 0;
int total = 0;
int average = 0;

CRGB leds[NUM_LEDS];

void setup(){
  Serial.begin(9600);

  for (int thisReading = 0; thisReading < numReadings; thisReading++) {
    readings[thisReading] = 0;
   } 

  FastLED.addLeds<NEOPIXEL, DATA_PIN>(leds, NUM_LEDS);
}

void loop() { 
  // smoothing analog input
  total = total - readings[readIndex];
  readings[readIndex] = analogRead(potInput);
  total = total + readings[readIndex];
  readIndex = readIndex + 1;

  if (readIndex >= numReadings) {
    readIndex = 0;
  }

  average = total / numReadings;
  
  // map smoothed potentiometer input to hue value of led's
  int hueValue = map(average, 0, 1023, 0, 255);
  
  // display chosen hue
  FastLED.showColor(CHSV(hueValue, 255, 191)); 
  delay(25);
}
