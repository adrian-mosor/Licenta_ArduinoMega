#include <Arduino.h>
#include "brightness.h"

int value;
int prev_light_intensity = 0;
int light_intensity_threshold = 20;

void update_led_light(int bright){

    Serial.println("UPDATED Real-time light intensity!"); // always printed in the first instance

    FastLED.setBrightness(bright);
    FastLED.show();
}

int get_intensity_of_light(){

    value = analogRead(KY018_PIN);
    return value;
}

void update_brightness_live(){

    int light_intensity = get_intensity_of_light();

    Serial.println(">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>");
    Serial.print("Live light intensity reported: ");
    Serial.println(light_intensity);
    Serial.println(">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>");

    if (abs(light_intensity - prev_light_intensity) <= light_intensity_threshold) {
        return; // skip updating if the difference is smaller or equal to the threshold
    }

    prev_light_intensity = light_intensity; // update the previous light intensity value

    //values reported smaller than 150 refers to the maximum level of environment bright
    if(light_intensity <= 200){

        update_led_light(1);
        
    }else
    if(light_intensity > 200 && light_intensity <= 300){

        update_led_light(2);
    }
    else
    if(light_intensity > 300 && light_intensity <= 400){

        update_led_light(3);
    }
    else
    if(light_intensity > 400 && light_intensity <= 700){

        update_led_light(4);
    }else
    if(light_intensity > 700){

        update_led_light(5);
    }

}