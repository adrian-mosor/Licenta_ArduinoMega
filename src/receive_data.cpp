#include "receive_data.h"

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
            print_hi();
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