#ifndef ESP8266_MANAGED_433MHZ_H
#define ESP8266_MANAGED_433MHZ_H

#include "config.h"
#include <Arduino.h>
#include "PubSubClient.h"

void tx433mhz_setup();
void tx433mhz_subscribe(PubSubClient mqtt_client);
void tx433mhz_mqtt_callback(String topic, String message);
void tx433mhz_switchWirelessSocket(const char* group, const char* device, bool on);
void tx433mhz_switch(uint16_t code);
void tx433mhz_transmit(int nHighPulses, int nLowPulses);

#endif //ESP8266_MANAGED_433MHZ_H
