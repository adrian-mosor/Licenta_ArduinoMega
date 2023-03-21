#pragma once
#include <SoftwareSerial.h>

extern SoftwareSerial espSerial; //linked to main

void send_data_to_esp8266();