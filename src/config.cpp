#include "config.h"

/*
 * HTTP Update
 */
const char* http_update_url = "http://192.168.0.10/firmware.bin";

/*
 * WiFi
 */
const char* wifi_ssid = "WiFiName";
const char* wifi_password = "wifipass";

/*
 * MQTT
 */
const char* mqtt_server = "broker.mqtt-dashboard.com";
const uint16_t mqtt_port = 1883;

/*
 * Infrared
 */
const unsigned int ir_led_pin = 12;
const String ir_topic = "foo/bar/ir/#";

/*
 * 433MHz Transmitter
 */
const unsigned int tx433mhz_pin = 14;
const String ws_topic = "foo/bar/wireless_socket/#";

/*
 * DHT11
 */
const int dht11_pin = 13;
const unsigned long dht11_publish_cycle = 1800000; // every half hour
const char* dht11_temperature_topic = "foo/bar/temperature";
const char* dht11_humidity_topic = "foo/bar/humidity";

/*
 * Contacts
 */
const int contacts_pins[10] = {5,4,16};  // don't use pin 0
const char* contacts_topics[10] = {"foo/bar/door","foo/bar/window","foo/bar/motion"};