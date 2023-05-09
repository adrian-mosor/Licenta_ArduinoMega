#include "receive_data.h"
#include "temperature.h"
#include "messages.h"

String receivedMessage;

void receive_data_from_esp8266(){

    if (Serial.available()) {   //receives messages from ESP coming from Android

        receivedMessage = Serial.readString();
        receivedMessage.trim(); //removes whitespaces and enters

        // Serial.println("Received message:");
        // Serial.print(receivedMessage);
        // Serial.println("-------------");

        if(receivedMessage.equals("rgb_hi")){
            
            Serial.println("Mega receiver: rgb_hi");
            FastLED.clear();    //clear the state of the matrix
            FastLED.show();

            print_hi_matrix();
            delay(500);
            
            FastLED.clear();
            FastLED.show();

            first_update_temp = TRUE_TEMP;
            first_update_hum = TRUE_HUM;

            float temperature = calculate_temperature();
            float humidity = calculate_humidity();

            if(temperature < 18){
                current_temperature_state = COLD;
            }
            else if(temperature >= 18 && temperature <= 26){
                current_temperature_state = MILD;
            }
            else if(temperature > 26){
                current_temperature_state = HOT;
            }

            if(humidity < 30){
                current_humidity_level = LOW_LEVEL;
            }
            else if(humidity >= 30 && humidity <= 50){
                current_humidity_level = MEDIUM_LEVEL;
            }
            else if(humidity > 50){
                current_humidity_level = HIGH_LEVEL;
            }

            print_temperature_matrix();
            print_humidity_matrix(); 

        }else
        if(receivedMessage.equals("rgb_reset")){
            
            Serial.println("Mega receiver: rgb_reset");
            FastLED.clear();
            FastLED.show();

        }else{
            
            Serial.println("Mega receiver: Wrong message");
         }
        
    }
}