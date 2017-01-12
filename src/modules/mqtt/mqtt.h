#ifndef ESP8266_MANAGED_MQTT_H
#define ESP8266_MANAGED_MQTT_H

#include "config.h"
#include <ESP8266WiFi.h>
#include "PubSubClient.h"

void setup_mqtt();
void mqtt_reconnect();
void mqtt_callback(char* topic, byte* payload, unsigned int length);
void mqtt_loop();

#endif //ESP8266_MANAGED_MQTT_H
