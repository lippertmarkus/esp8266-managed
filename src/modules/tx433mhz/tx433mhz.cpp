#include "tx433mhz.h"

void tx433mhz_setup() {
    pinMode(tx433mhz_pin, OUTPUT);
}

void tx433mhz_subscribe(PubSubClient mqtt_client) {
    Serial.print("Subscribing to ");
    Serial.println(ws_topic);
    mqtt_client.subscribe(ws_topic.c_str());
}

void tx433mhz_mqtt_callback(String topic, String message) {
    String intopic = topic.substring(0, ws_topic.length()-1);
    String checktopic = ws_topic.substring(0, ws_topic.length()-1);

    if(intopic.equals(checktopic)) {
        String group = topic.substring(ws_topic.length()-1, ws_topic.length()+4);
        String device = topic.substring(ws_topic.length()+5, ws_topic.length()+11);

        bool switchOn;
        Serial.print("Switching ");

        if (message.equals("ON")) {
            switchOn = true;
            Serial.print("on");
        } else if(message.equals("OFF")) {
            switchOn = false;
            Serial.print("off");
        } else {
            Serial.println("nothing because of invalid data.");
            return;
        }

        Serial.println(" wireless socket with group code " + group + " and device code " + device);
        tx433mhz_switchWirelessSocket(group.c_str(), device.c_str(), switchOn);
    }
}

void tx433mhz_switchWirelessSocket(const char* group, const char* device, bool on) {
    char cmd[13];
    strcpy(cmd, group);
    strcat(cmd, device);

    if (on) {
        strcat(cmd, "10");
    }
    else {
        strcat(cmd, "01");
    }

    tx433mhz_switch(strtol(cmd, NULL, 2));
}

void tx433mhz_switch(uint16_t code) {
    for (int nRepeat=0; nRepeat<6; nRepeat++) {
        for (int i=4; i<16; i++) {
            tx433mhz_transmit(1,3);
            if (((code << (i-4)) & 2048) > 0) {
                tx433mhz_transmit(1,3);
            } else {
                tx433mhz_transmit(3,1);
            }
        }
        tx433mhz_transmit(1,31);
    }
}

void tx433mhz_transmit(int nHighPulses, int nLowPulses) {
    digitalWrite(tx433mhz_pin, HIGH);
    delayMicroseconds(350 * nHighPulses);
    digitalWrite(tx433mhz_pin, LOW);
    delayMicroseconds(350 * nLowPulses);
}