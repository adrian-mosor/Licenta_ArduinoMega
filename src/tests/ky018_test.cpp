#include <Arduino.h>

#define KY018_PIN A0
// int sensorPin = A0; // Declaration of the input pin

int value = 0;

void setup(){

    Serial.begin(9600);
}

void loop(){

    value = analogRead(KY018_PIN);  //higher the value, higher the darkness
    Serial.println(value);

    delay(1500);
}