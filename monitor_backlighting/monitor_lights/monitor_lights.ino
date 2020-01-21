#include <FastLED.h>
#include <pixeltypes.h>

// WS2812B LED information
#define NUM_LEDS 56
#define DATA_PIN 5

// potentiometer input pin
const int potInput = A2;

// array size for input smoothing
const int batch = 10;

int readings[batch];
int index = 0;
int sum = 0;
int average = 0;

CRGB leds[NUM_LEDS];

void setup(){
  Serial.begin(9600);

  for (int sample = 0; sample < batch; sample++) {
    readings[sample] = 0;
   } 

  FastLED.addLeds<NEOPIXEL, DATA_PIN>(leds, NUM_LEDS);
}

void loop() { 
  // smoothing analog input
  sum = sum - readings[index];

  readings[index] = analogRead(potInput);
  sum = sum + readings[index];

  index = index + 1;

  if (index >= batch) {
    index = 0;
  }

  average = sum / batch;
  
  // map smoothed potentiometer input to hue value of leds
  int hueValue = map(average, 0, 1023, 0, 255);
  
  // display avg hue
  FastLED.showColor(CHSV(hueValue, 255, 191)); 
  delay(25);
}
