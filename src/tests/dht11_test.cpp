// DHT11 test

#include <Arduino.h>
#include "Adafruit_Sensor.h"
#include "dht.h"

#define DHTPIN 8
#define DHTTYPE DHT11   // DHT 11

DHT dht(DHTPIN, DHTTYPE);

void setup(){

    Serial.begin(9600);
    Serial.println("DHT begin");
    dht.begin();
    Serial.println("Ready DHT");
}

void loop(){

    delay(2000);
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

    //print humidity
    Serial.print(F("Humidity: "));
    Serial.print(h);
    Serial.println(F(" %"));

    //print temperature
    Serial.print(F("Temperature: "));
    Serial.print(t);
    Serial.println(F(" C"));


    Serial.print(F("Temperature: "));
    Serial.print(f);
    Serial.println(F(" F"));

    Serial.println("\n----------------\n");
}


