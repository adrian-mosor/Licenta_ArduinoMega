#include "temperature.h"

void print_temperature(){

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
}

float* calculate_dht11(){

    float* temp = new float[3]{-1, -1, -1};
    delay(2000);
    float h = dht.readHumidity();
    // Read temperature as Celsius (the default)
    float t = dht.readTemperature();
    // Read temperature as Fahrenheit (isFahrenheit = true)
    float f = dht.readTemperature(true);

    if (isnan(h) || isnan(t) || isnan(f)) {
      Serial.println(F("Failed to read from DHT sensor!"));
      return temp;
    }

    temp[0] = h; temp[1] = t; temp[2] = f;

    return temp;    
}

float calculate_temperature(){

    float t = dht.readTemperature();

    if (isnan(t)) {
      Serial.println(F("Failed to read temperature from DHT sensor!"));
      return -1;
    }

    return t;

}

float calculate_temperature_f(){


    float f = dht.readTemperature(true);

    if (isnan(f)) {
      Serial.println(F("Failed to read temperature from DHT sensor!"));
      return -1;
    }

    return f;

}

float calculate_humidity(){

    float h = dht.readHumidity();

    if (isnan(h)) {
      Serial.println(F("Failed to read humidity from DHT sensor!"));
      return -1;
    }

    return h;
}
