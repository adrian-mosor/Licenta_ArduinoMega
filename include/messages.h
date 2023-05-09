#pragma once
#include "prints.h"

enum TemperatureState{
    NOT_DEFINED_STATE,
    COLD,
    MILD,
    HOT
};

enum HumidityLevel{
    NOT_DEFINED_LEVEL,
    LOW_LEVEL,
    MEDIUM_LEVEL,
    HIGH_LEVEL 
};

enum FirstUpdateTemperature{
    NOT_DEFINED_TEMP,
    FALSE_TEMP,
    TRUE_TEMP
};

enum FirstUpdateHumidity{
    NOT_DEFINED_HUM,
    FALSE_HUM,
    TRUE_HUM
};

// declared in main.cpp
extern TemperatureState current_temperature_state;  
extern HumidityLevel current_humidity_level;
extern FirstUpdateTemperature first_update_temp;
extern FirstUpdateHumidity first_update_hum;

void print_hi_matrix();
void print_temperature_matrix();
void print_humidity_matrix();

// shape objects for temperature
void print_snowflake_matrix();
void print_leaf_matrix();
void print_sun_matrix();

//shape objects for humiidity
void print_low_humidity_matrix();
void print_medium_humidity_matrix();
void print_high_humidity_matrix();

void turn_off_leds_temperature_matrix();
void turn_off_leds_humidity_matrix();
void update_live_matrix();