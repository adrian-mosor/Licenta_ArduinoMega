#include <Arduino.h>
#include "fast_led.h"
#include "messages.h"
#include "temperature.h"
#include "send_data.h"

#define LED_PIN 9
#define BRIGHTNESS 10
#define DHTPIN 8
#define DHTTYPE DHT11 // DHT 11

bool hi_flag = false;
bool dht_flag = false;
bool test_flag = true;

CRGB leds[NUM_LEDS];
DHT dht(DHTPIN, DHTTYPE);
String receivedMessage;
SoftwareSerial espSerial(5, 6); //for sending data to esp

void setup()
{   
    pinMode(LED_BUILTIN, OUTPUT);
    digitalWrite(LED_BUILTIN, LOW);   // turn the LED off by making the voltage LOW

    Serial.begin(9600);
    espSerial.begin(9600);    
    while (!Serial)
    {
      ; // wait for serial port to connect. Needed for native USB port only
    }
    Serial.println();
    Serial.println();
    Serial.println("Production: Mega ready to receive. Please connect RX pin!");

    dht.begin();
    FastLED.addLeds<WS2812, LED_PIN, GRB>(leds, NUM_LEDS);
    FastLED.setBrightness(BRIGHTNESS);

    FastLED.clear(); // update the state of the matrix
    FastLED.show();

    // print_hi();

    digitalWrite(LED_BUILTIN, HIGH);  // turn the LED on (HIGH is the voltage level)

}

void loop()
{
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
    
    send_data_to_esp8266(); //send data from sensors to esp8266, so it can send further to ThingSpeak

}