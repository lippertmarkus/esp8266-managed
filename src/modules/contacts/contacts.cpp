#include "contacts.h"

const int count = sizeof(contacts_pins)/ sizeof(contacts_pins[0]);
int lastValues[count];

void contacts_setup() {
    // init with -1 so that contact states are sent once after boot
    for (int i = 0; i < count; i++) {
        lastValues[i] = -1;

        if(contacts_pins[i] > 0) pinMode(contacts_pins[i], INPUT);
    }
}

void contacts_publish(PubSubClient mqtt_client) {
    for (int i = 0; (i < count) && (contacts_pins[i] > 0); i++) {
        int newValue = digitalRead(contacts_pins[i]);

        if(lastValues[i] != newValue) {
            lastValues[i] = newValue;
            const char* msg;

            if(newValue == 1) msg = "CLOSED";
            else msg = "OPEN";

            Serial.print("Publishing ");
            Serial.print(msg);
            Serial.print(" to ");
            Serial.println(contacts_topics[i]);

            mqtt_client.publish(contacts_topics[i], msg, true);
        }
    }
}