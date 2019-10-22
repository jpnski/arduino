#include <FastLED.h>
#include <pixeltypes.h>

#define NUM_LEDS 56
#define DATA_PIN 5

const int potInput = A2;

CRGB leds[NUM_LEDS];

void setup(){
Serial.begin(9600);
FastLED.addLeds<NEOPIXEL, DATA_PIN>(leds, NUM_LEDS);
}

void loop() { 
int hueValue = map(analogRead(potInput), 0, 1023, 0, 255);
FastLED.showColor(CHSV(hueValue, 255, 191)); 
delay(25);
}
