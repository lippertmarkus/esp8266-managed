#ifndef ESP8266_MANAGED_CONTACTS_H
#define ESP8266_MANAGED_CONTACTS_H

#include "config.h"
#include "PubSubClient.h"

void contacts_setup();
void contacts_publish(PubSubClient mqtt_client);

#endif //ESP8266_MANAGED_CONTACTS_H
