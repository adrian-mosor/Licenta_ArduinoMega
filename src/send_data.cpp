#include "send_data.h"

#include <ArduinoJson.h>
#include "temperature.h"

String tx_jsonString;

void send_data_to_esp8266(){

    StaticJsonDocument<50> doc;
    doc["Type of sensor: "] = "dht";
    doc["Humidity: "] = calculate_humidity();
    doc["TemperatureC: "] = calculate_temperature();
    doc["TemperatureF: "] = calculate_temperature_f();

    serializeJson(doc, tx_jsonString); //convert doc object to a string and store it in tx_jsonString

    Serial.println("Sent message!");
    Serial.println(tx_jsonString);

    espSerial.println(tx_jsonString); //send to esp8266
    tx_jsonString = "";
    
    delay(1000);

}