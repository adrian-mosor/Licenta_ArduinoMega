#pragma once

#include "Adafruit_Sensor.h"
#include "dht.h"

extern DHT dht; //linked to main

void print_temperature();
float* calculate_dht11();
float calculate_temperature();
float calculate_temperature_f();
float calculate_humidity();
void debug_temp();