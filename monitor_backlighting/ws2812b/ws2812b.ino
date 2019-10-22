#include <FastLED.h>

#define NUM_LEDS 1
#define DATA_PIN 5

CRGB leds[NUM_LEDS];

void setup(){
FastLED.addLeds<WS2812B, DATA_PIN, RGB>(leds, NUM_LEDS);
}

void loop() {
    for(int i=0; i<NUM_LEDS; i++){
        leds[i] = CHSV(160, 255, 128);
        FastLED.show();
        delay(50);
        leds[i];
        FastLED.show();
    }
}
