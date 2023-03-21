#include "fast_led.h"
#include "prints.h"

void print_with_delay(int start, int end, unsigned long color, int delay_seconds){

  if(start < end){
    
    for(int i = start; i <= end; i++){
      leds[i] = color;
      FastLED.show();
      delay(delay_seconds);
    } 
  }
  else
  if(start > end){

    for(int i = start; i >= end; i--){
      leds[i] = color;
      FastLED.show();
      delay(delay_seconds);
    }
  }
}