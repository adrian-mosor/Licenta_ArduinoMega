#include <Arduino.h>

int sensorPin = A0; // Declaration of the input pin

int value = 0;

void setup(){

    Serial.begin(9600);
}

void loop(){

    value = analogRead(sensorPin);
    Serial.println(value, DEC);

    delay(1500);
}