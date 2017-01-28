#ifndef ESP8266_MANAGED_MQTT_H
#define ESP8266_MANAGED_MQTT_H

#include "config.h"
#include "Arduino.h"
#include <ESP8266WiFi.h>
#include <PubSubClient.h>
#include "modules/system/system.h"
#include "modules/tx433mhz/tx433mhz.h"
#include "modules/ir/ir.h"
#include "modules/dht11/dht11.h"
#include "modules/contacts/contacts.h"

void mqtt_setup();
void mqtt_loop();
void mqtt_callback(char* topic, byte* payload, unsigned int length);
void mqtt_reconnect();
void mqtt_subscribe();
void mqtt_publish();

#endif //ESP8266_MANAGED_MQTT_H
