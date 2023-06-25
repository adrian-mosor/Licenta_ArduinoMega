// Test Matrix

#include <Arduino.h>
#include <FastLED.h>
#include "messages.h"

#define LED_PIN 9
#define BRIGHTNESS 1
#define NUM_LEDS 256

CRGB leds[NUM_LEDS];
bool hi_flag = false;

int bright = 0;

void increment_brightness()
{
    bright += 1;
}

void setup()
{
    // put your setup code here, to run once:
    
    Serial.println("RGB_TEST");
    Serial.begin(9600);

    Serial.println(">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>");
    Serial.print("Setting brightness to: ");
    Serial.println(bright);
    Serial.println(">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>");

    FastLED.addLeds<WS2812, LED_PIN, GRB>(leds, NUM_LEDS);
    FastLED.setBrightness(BRIGHTNESS);

    FastLED.clear(); // update the state of the matrix
    FastLED.show();

    print_hi_matrix();

    //test-case for low-temperature scenario:
    FastLED.clear(); // update the state of the matrix
    FastLED.show();
    print_snowflake_matrix();
}

void loop()
{

    // test-cases used for brightness treshold values:
    // if(hi_flag == false){

    //     for (int i = 0; i < 10; i++)    //max value = increment * steps
    //     {
    //         delay(2000);
    //         increment_brightness();
    //         Serial.println(">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>");
    //         Serial.print("Setting brightness to: ");
    //         Serial.println(bright);
    //         Serial.println(">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>");
    //         FastLED.setBrightness(bright);
    //         FastLED.show();
    //     }

    //     hi_flag = true;
    // }

    // delay(2000);
    // FastLED.setBrightness(250);
    // FastLED.show();

    // delay(2000);
}
