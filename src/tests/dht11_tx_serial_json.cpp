// DHT11 Data from MEGA -> ESP

#include <Arduino.h>
#include <ArduinoJson.h>
#include <SoftwareSerial.h>
#include "Adafruit_Sensor.h"
#include "dht.h"

#define DHTPIN 8
#define DHTTYPE DHT11   // DHT 11

SoftwareSerial espSerial(5, 6);
DHT dht(DHTPIN, DHTTYPE);

String tx_jsonString;

void setup(){

    Serial.begin(9600);
    espSerial.begin(9600);
    Serial.println("DHT begin");
    dht.begin();
    Serial.println("Ready DHT");
    Serial.println("Mega begin to transmit");
}

void loop(){

    float h = dht.readHumidity();
    // Read temperature as Celsius (the default)
    float t = dht.readTemperature();
    // Read temperature as Fahrenheit (isFahrenheit = true)
    float f = dht.readTemperature(true);

    // Check if any reads failed and exit early (to try again).
    if (isnan(h) || isnan(t) || isnan(f)) {
      Serial.println(F("Failed to read from DHT sensor!"));
      return;
    }

    StaticJsonDocument<50> doc;
    doc["Type of sensor: "] = "dht";
    doc["Humidity: "] = h;
    doc["TemperatureC: "] = t;
    doc["TemperatureF: "] = f;

    serializeJson(doc, tx_jsonString); //convert doc object to a string and store it in tx_jsonString

    // Serial.println(tx_jsonString);
    espSerial.println(tx_jsonString); //send to esp8266
    tx_jsonString = "";
    
    delay(1000);
}


