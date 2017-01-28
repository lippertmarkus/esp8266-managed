#ifndef ESP8266_MANAGED_IR_H
#define ESP8266_MANAGED_IR_H

#include "config.h"
#include <IRremoteESP8266.h>
#include "Arduino.h"
#include <PubSubClient.h>

void ir_setup();
void ir_subscribe(PubSubClient mqtt_client);
void ir_mqtt_callback(String topic, String message);
void ir_sendSamsung(const char* code);
void ir_sendNEC(const char *code);

#endif //ESP8266_MANAGED_IR_H
