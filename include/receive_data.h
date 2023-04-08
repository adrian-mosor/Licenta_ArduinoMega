#pragma once
#include <Arduino.h>
#include "fast_led.h"
#include "messages.h"
#include "prints.h"

extern String receivedMessage;

void receive_data_from_esp8266();