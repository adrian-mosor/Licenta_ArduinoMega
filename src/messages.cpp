#include "fast_led.h"
#include "messages.h"
#include "temperature.h"

void print_hi_matrix()
{
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

void print_temperature_matrix()
{   
    if(first_update_temp == NOT_DEFINED_TEMP || current_temperature_state == NOT_DEFINED_STATE){

        return ;
    }

    float temp = calculate_temperature();
    Serial.print("Real-time update matrix state temperature: ");
    Serial.println(temp);

    TemperatureState new_temperature_state;

    if(temp < 18){
        new_temperature_state = COLD;
    }
    else if(temp >= 18 && temp <= 26){
        new_temperature_state = MILD;
    }
    else if(temp > 26){
        new_temperature_state = HOT;
    }

    if(first_update_temp == TRUE_TEMP){

        if(current_temperature_state == COLD){
            
            print_snowflake_matrix();
        }
        else if(current_temperature_state == MILD){
            
            print_leaf_matrix();
        }
        else if(current_temperature_state == HOT){

            print_sun_matrix();
        }

        first_update_temp = FALSE_TEMP;
    }
    else if (first_update_temp == FALSE_TEMP && new_temperature_state != current_temperature_state) {
        
        current_temperature_state = new_temperature_state;  //update current with the new state

        turn_off_leds_temperature_matrix();

        if(current_temperature_state == COLD){  // cold - snowflake

            print_snowflake_matrix();
        }
        else if(current_temperature_state == MILD){ // mild - leaf 

            print_leaf_matrix();
        }
        else if(current_temperature_state == HOT){  // hot - sun

            print_sun_matrix();
        }

    }
}

void print_humidity_matrix(){

    if(first_update_hum == NOT_DEFINED_HUM || current_humidity_level == NOT_DEFINED_LEVEL){
        return ;
    }

    float hum = calculate_humidity();
    Serial.print("Real-time update matrix state humidity: ");
    Serial.println(hum);

    HumidityLevel new_humidity_level;

    if(hum < 30){
        new_humidity_level = LOW_LEVEL;
    }
    else if(hum >= 30 && hum <= 50){
        new_humidity_level = MEDIUM_LEVEL;
    }
    else if(hum > 50){
        new_humidity_level = HIGH_LEVEL;
    }

    if(first_update_hum == TRUE_HUM){

        if(current_humidity_level == LOW_LEVEL){
            
            print_low_humidity_matrix();
        }
        else if(current_humidity_level == MEDIUM_LEVEL){
            
            print_medium_humidity_matrix();
        }
        else if(current_humidity_level == HIGH_LEVEL){

            print_high_humidity_matrix();
        }

        first_update_hum = FALSE_HUM;
    }
    else if (first_update_hum == FALSE_HUM && new_humidity_level != current_humidity_level) {
        
        current_humidity_level = new_humidity_level;  //update current with the new state

        turn_off_leds_humidity_matrix();

        if(current_humidity_level == LOW_LEVEL){  // low humidity

            print_low_humidity_matrix();
        }
        else if(current_humidity_level == MEDIUM_LEVEL){ // medium humidity

            print_medium_humidity_matrix();
        }
        else if(current_humidity_level == HIGH_LEVEL){  // high_humidity

            print_high_humidity_matrix();
        }

    }
    
}

void print_low_humidity_matrix(){

    print_with_fade(57, CRGB::MediumSpringGreen, 0);
    print_with_fade(38, CRGB::MediumSpringGreen, 80);
    print_with_fade(56, CRGB::MediumSpringGreen, 0);
    print_with_fade(39, CRGB::MediumSpringGreen, 80);
    print_with_fade(55, CRGB::MediumSpringGreen, 0);
    print_with_fade(40, CRGB::MediumSpringGreen, 0);
}

void print_medium_humidity_matrix(){

    print_low_humidity_matrix();

    print_with_fade(54, CRGB::Orange, 0);
    print_with_fade(41, CRGB::Orange, 80);
    print_with_fade(53, CRGB::Orange, 0);
    print_with_fade(42, CRGB::Orange, 80);
    print_with_fade(52, CRGB::Orange, 0);
    print_with_fade(43, CRGB::Orange, 0);
}

void print_high_humidity_matrix(){

    print_medium_humidity_matrix();

    print_with_fade(51, CRGB::Red, 0);
    print_with_fade(44, CRGB::Red, 80);
    print_with_fade(50, CRGB::Red, 0);
    print_with_fade(45, CRGB::Red, 80);
    print_with_fade(49, CRGB::Red, 0);
    print_with_fade(46, CRGB::Red, 0);
}

void print_snowflake_matrix(){

    print_with_fade(199, CRGB::DodgerBlue, 180);
    print_with_fade(184, CRGB::DodgerBlue, 180);
    print_with_fade(183, CRGB::DodgerBlue, 180);
    print_with_fade(200, CRGB::DodgerBlue, 180);
    print_with_fade(214, CRGB::DodgerBlue, 180);
    print_with_fade(169, CRGB::DodgerBlue, 180);
    print_with_fade(234, CRGB::DodgerBlue, 180);
    print_with_fade(149, CRGB::DodgerBlue, 180);
    print_with_fade(148, CRGB::DodgerBlue, 180);
    print_with_fade(235, CRGB::DodgerBlue, 180);
    print_with_fade(211, CRGB::DodgerBlue, 180);
    print_with_fade(172, CRGB::DodgerBlue, 180);
    print_with_fade(178, CRGB::DodgerBlue, 180);
    print_with_fade(205, CRGB::DodgerBlue, 180);
    print_with_fade(206, CRGB::DodgerBlue, 180);
    print_with_fade(177, CRGB::DodgerBlue, 180);
    print_with_fade(203, CRGB::DodgerBlue, 180);
    print_with_fade(181, CRGB::DodgerBlue, 180);
    print_with_fade(202, CRGB::DodgerBlue, 180);
    print_with_fade(180, CRGB::DodgerBlue, 0);
}

void print_leaf_matrix(){

    print_with_fade(206, CRGB::LawnGreen, 180);
    print_with_fade(205, CRGB::LawnGreen, 180);
    print_with_fade(204, CRGB::LawnGreen, 180);
    print_with_fade(211, CRGB::LawnGreen, 180);
    print_with_fade(204, CRGB::LawnGreen, 180);
    print_with_fade(179, CRGB::LawnGreen, 180);
    print_with_fade(212, CRGB::LawnGreen, 180);
    print_with_fade(203, CRGB::LawnGreen, 180);
    print_with_fade(180, CRGB::LawnGreen, 180);
    print_with_fade(213, CRGB::LawnGreen, 0);   //delay is after
    print_with_fade(181, CRGB::LawnGreen, 180);
    print_with_fade(214, CRGB::LawnGreen, 180);
    print_with_fade(201, CRGB::LawnGreen, 180);
    print_with_fade(182, CRGB::LawnGreen, 180);
    print_with_fade(215, CRGB::LawnGreen, 180);
    print_with_fade(200, CRGB::LawnGreen, 180);
    print_with_fade(183, CRGB::LawnGreen, 180);
    print_with_fade(199, CRGB::LawnGreen, 180);
    print_with_fade(198, CRGB::LawnGreen, 0);
}

void print_sun_matrix(){

    print_with_fade(199, CRGB::Yellow, 80);
    print_with_fade(215, CRGB::Yellow, 80);
    print_with_fade(233, CRGB::Yellow, 80);
    print_with_fade(245, CRGB::Yellow, 80);
    print_with_fade(235, CRGB::Yellow, 80);
    print_with_fade(211, CRGB::Yellow, 80);
    print_with_fade(205, CRGB::Yellow, 80);
    print_with_fade(178, CRGB::Yellow, 80);
    print_with_fade(172, CRGB::Yellow, 80);
    print_with_fade(148, CRGB::Yellow, 80);
    print_with_fade(138, CRGB::Yellow, 80);
    print_with_fade(150, CRGB::Yellow, 80);
    print_with_fade(168, CRGB::Yellow, 80);
    print_with_fade(184, CRGB::Yellow, 80);
    print_with_delay(204, 200, CRGB::Yellow, 180);
    print_with_delay(179, 183, CRGB::Yellow, 180);
    print_with_delay(171, 169, CRGB::Yellow, 180);
    print_with_delay(212, 214, CRGB::Yellow, 180);
    print_with_delay(204, 200, CRGB::Yellow, 20);
    print_with_fade(234, CRGB::Yellow, 0);
    print_with_fade(149, CRGB::Yellow, 0);
}

void turn_off_leds_temperature_matrix(){

    // the indices used by all the forms
    int indices[] = {
        138, 139, 148, 149, 150, 168, 169, 170, 171, 172, 173, 178, 179, 180, 181, 182, 183, 184, 198, 199, 200, 201, 202, 203, 204, 205, 206, 211, 212, 213, 214, 215, 233, 234, 235, 245
    };
    // turn off all LEDs with the above indices
    for (int i = 0; i < sizeof(indices) / sizeof(indices[0]); i++) {
        leds[indices[i]] = CRGB::Black;
    }
    FastLED.show();
}

void turn_off_leds_humidity_matrix(){

    // the indices used by all humidity levels
    int indices[] = { 58, 37, 57, 38, 56, 39, 55, 40, 54, 41, 53, 42, 52, 43, 51, 44, 50, 45
    };

    // turn off all LEDs with the above indices
    for (int i = 0; i < sizeof(indices) / sizeof(indices[0]); i++) {
        leds[indices[i]] = CRGB::Black;
    }
    FastLED.show();
}

void update_live_matrix(){

    print_temperature_matrix();
    print_humidity_matrix();
}