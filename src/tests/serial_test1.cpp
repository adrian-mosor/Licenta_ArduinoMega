// MEGA -> ESP

#include <Arduino.h>
#include <SoftwareSerial.h>

SoftwareSerial espSerial(5, 6); //RX, TX
String temp;
String str, str1;

void setup(){
  
  Serial.begin(9600);
  espSerial.begin(9600);
  Serial.println("Mega begin to transmit");
  delay(1000);
}


void loop()
{

    float h = 13;
    float t = 19;

    str = String("coming from adi arduino: ")+String("H= ")+String(h)+String("T= ")+String(t);
    str1 = String("welcome!");
    temp = String(t);

    // espSerial.println(str); //send to esp8266
    // espSerial.println(str1);
    espSerial.println(temp);
    
    delay(1000);

}