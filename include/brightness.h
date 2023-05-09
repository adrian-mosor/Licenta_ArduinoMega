#pragma once

#include "fast_led.h"

#define KY018_PIN A0

extern int value;
extern int prev_light_intensity;
extern int light_intensity_threshold;

int get_intensity_of_light();
void update_brightness_live();
void update_led_light(int bright);