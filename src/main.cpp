#include <Arduino.h>
#include "fast_led.h"
#include "messages.h"
#include "temperature.h"
#include "send_data.h"
#include "receive_data.h"
#include "brightness.h"

#define LED_PIN 9
#define BRIGHTNESS 2
#define DHTPIN 8
#define DHTTYPE DHT11 // DHT 11

bool hi_flag = false;
bool dht_flag = false;
bool test_flag = true;

FirstUpdateTemperature first_update_temp = NOT_DEFINED_TEMP;
FirstUpdateHumidity first_update_hum = NOT_DEFINED_HUM;

TemperatureState current_temperature_state = NOT_DEFINED_STATE;
HumidityLevel current_humidity_level = NOT_DEFINED_LEVEL;

CRGB leds[NUM_LEDS];
DHT dht(DHTPIN, DHTTYPE);
SoftwareSerial espSerial(5, 6); // for sending data to esp

void setup()
{
    pinMode(LED_BUILTIN, OUTPUT);
    digitalWrite(LED_BUILTIN, LOW); // turn the LED off by making the voltage LOW

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

    FastLED.clear(); // clear the state of the matrix
    FastLED.show();

    // print_hi_matrix();

    digitalWrite(LED_BUILTIN, HIGH); // turn the LED on (HIGH is the voltage level)
}

void loop()
{   
    update_brightness_live();   // update real-time brightness

    receive_data_from_esp8266(); // receive data from Android app via esp8266

    send_data_to_esp8266(); // send data from sensors to esp8266, so it can send further to ThingSpeak

    update_live_matrix();   // update real-time shapes on the matrix in sync with the sensor values

}