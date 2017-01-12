#ifndef ESP8266_MANAGED_CONFIG_H
#define ESP8266_MANAGED_CONFIG_H

#include <stdint.h>

/*
 * WiFi
 */
extern const char* ssid;
extern const char* password;

/*
 * MQTT
 */
extern const char* mqtt_server;
extern const uint16_t mqtt_port;

#endif //ESP8266_MANAGED_CONFIG_H
