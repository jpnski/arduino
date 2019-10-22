#include <FastLED.h>
#include <pixeltypes.h>

// monitor backlighting using ws2812b led's
// hue controlled by potentiometer

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
FastLED.showColor(CHSV(hueValue, 255, 255)); 
delay(10);
}
