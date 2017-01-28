#ifndef ESP8266_MANAGED_SYSTEM_H
#define ESP8266_MANAGED_SYSTEM_H

#include <PubSubClient.h>
#include "modules/httpUpdate/httpUpdate.h"

void system_subscribe(PubSubClient mqtt_client);
void system_mqtt_callback(String intopic, String message);

#endif //ESP8266_MANAGED_SYSTEM_H
