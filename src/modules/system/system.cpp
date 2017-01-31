#include "system.h"

void system_subscribe(PubSubClient mqtt_client) {
    String topic = WiFi.hostname();
    Serial.println("Subscribing to system topic " + topic);
    mqtt_client.subscribe(topic.c_str());
}

void system_mqtt_callback(String intopic, String message) {
    String topic = WiFi.hostname();

    if(intopic.equals(topic)) {
        if(message.equals("update")) {
            Serial.println("Updating firmware..");
            updateFirmware();
        } else if(message.equals("reboot")) {
            Serial.println("Rebooting in 3 seconds..");
            delay(3000);
            ESP.restart();
        }
    }
}