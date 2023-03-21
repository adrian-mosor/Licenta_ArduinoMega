// Reset Matrix

#include <Arduino.h>
#include <FastLED.h>

#define LED_PIN 9
#define BRIGHTNESS 5
#define NUM_LEDS 256

CRGB leds[NUM_LEDS];
bool hi_flag = false;

void setup() {
  // put your setup code here, to run once:

  FastLED.addLeds<WS2812, LED_PIN, GRB>(leds, NUM_LEDS);
  FastLED.setBrightness(BRIGHTNESS);

  FastLED.clear();  //update the state of the matrix
  FastLED.show();
}

void loop(){

    
}
