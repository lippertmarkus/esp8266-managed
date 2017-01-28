#include "system.h"

void system_subscribe(PubSubClient mqtt_client) {
    String topic = WiFi.hostname() + "/#";
    Serial.println("Subscribing to system topic " + topic);
    mqtt_client.subscribe(topic.c_str());
}

void system_mqtt_callback(String intopic, String message) {
    char *topic = (char*)intopic.c_str();
    char *base = strtok(topic, "/");

    String wifi_host = WiFi.hostname();
    const char *hostname = wifi_host.c_str();

    if(strcmp(base, hostname) == 0) {
        char *function = strtok(NULL, "/");

        if (strcmp(function, "update") == 0) {
            Serial.println("Updating firmware..");
            updateFirmware();
        }

        if (strcmp(function, "reboot") == 0) {
            Serial.println("Rebooting in 3 seconds..");
            delay(3000);
            ESP.restart();
        }
    }
}