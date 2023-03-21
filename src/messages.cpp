#include "fast_led.h"
#include "messages.h"

void print_hi(){

  print_with_delay(163, 172, CRGB::SkyBlue, 100);

  leds[151] = CRGB::SkyBlue;
  leds[136] = CRGB::SkyBlue;
  leds[152] = CRGB::SkyBlue;
  leds[135] = CRGB::SkyBlue;
  FastLED.show();

  delay(100);

  print_with_delay(115, 124, CRGB::SkyBlue, 100);

  print_with_delay(92, 84, CRGB::SkyBlue, 100);

  leds[82] = CRGB::SkyBlue;
  FastLED.show();
  
}

