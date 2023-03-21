//Mega receives from ESP

#include <Arduino.h>
#include <FastLED.h>

String receivedMessage;

#define LED_PIN 9
#define BRIGHTNESS 5
#define NUM_LEDS 256

CRGB leds[NUM_LEDS];

void setup() {

    // Open serial communications and wait for port to open:
    Serial.begin(9600);

    FastLED.addLeds<WS2812, LED_PIN, GRB>(leds, NUM_LEDS);
    FastLED.setBrightness(BRIGHTNESS);

    FastLED.clear();  
    FastLED.show(); //update the state of the matrix

    Serial.println();
    Serial.println("Mega ready to receive. Please connect RX pin!");
    
    while (!Serial) {
    ; // wait for serial port to connect. Needed for native USB port only
    }
}
void loop() { // run over and over

    if (Serial.available()) {   //example of printing on serial monitor directly 

        // Serial.write(Serial.read());

        // receivedMessage = Serial.readString();
        // receivedMessage.trim(); //removes whitespaces and enters

        Serial.println("Received message:");
        Serial.print(receivedMessage);
        Serial.println("-------------");

        //web_command_test
        // if(receivedMessage.equals("rgb_on_test")){
            
        //     Serial.println("Mega receiver: Entered in equals!");
        //     leds[240] = CRGB::SkyBlue;
        //     FastLED.show();
        // }else{

        //     Serial.println("Mega receiver: Wrong message");
        // }
        
    }
}