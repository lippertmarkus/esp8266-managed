#ifndef ESP8266_MANAGED_CONFIG_H
#define ESP8266_MANAGED_CONFIG_H

#include <stdint.h>
#include <WString.h>

/*
 * HTTP Update
 */
extern const char* http_update_url;

/*
 * WiFi
 */
extern const char* wifi_ssid;
extern const char* wifi_password;

/*
 * MQTT
 */
extern const char* mqtt_server;
extern const uint16_t mqtt_port;

/*
 * Infrared
 */
extern const unsigned int ir_led_pin;
extern const String ir_topic;

/*
 * 433MHz Transmitter
 */
extern const unsigned int tx433mhz_pin;
extern const String ws_topic;

/*
 * DHT11
 */
extern const int dht11_pin;
extern const unsigned long dht11_publish_cycle;
extern const char* dht11_temperature_topic;
extern const char* dht11_humidity_topic;

/*
 * Contacts
 */
extern const int contacts_pins[10];
extern const char* contacts_topics[10];

#endif //ESP8266_MANAGED_CONFIG_H
