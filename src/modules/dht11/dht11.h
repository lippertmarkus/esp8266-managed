#ifndef ESP8266_MANAGED_DHT11_H
#define ESP8266_MANAGED_DHT11_H

#include "SimpleDHT.h"
#include "config.h"
#include "PubSubClient.h"

void dht11_publish(PubSubClient mqtt_client);
void dht11_publishSensorData(PubSubClient mqtt_client);

#endif //ESP8266_MANAGED_DHT11_H
