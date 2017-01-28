#include "ir.h"

IRsend irsend(ir_led_pin);

void ir_setup() {
    irsend.begin();
}

void ir_subscribe(PubSubClient mqtt_client) {
    Serial.print("Subscribing to ");
    Serial.println(ir_topic);
    mqtt_client.subscribe(ir_topic.c_str());
}

void ir_mqtt_callback(String topic, String message) {
    String intopic = topic.substring(0, ir_topic.length()-1);
    String checktopic = ir_topic.substring(0, ir_topic.length()-1);

    if(intopic.equals(checktopic)) {
        String type = topic.substring(ir_topic.length()-1, ir_topic.length()+2);

        if(type.equals("sam")) {
            Serial.println("Sending IR Samsung code " + message);
            ir_sendSamsung(message.c_str());
        } else if(type.equals("nec")) {
            Serial.println("Sending IR NEC code " + message);
            ir_sendNEC(message.c_str());
        }
    }
}

void ir_sendSamsung(const char* code) {
    irsend.sendSAMSUNG(strtoul(code, NULL, 16), 32);
}

void ir_sendNEC(const char *code) {
    irsend.sendNEC(strtoul(code, NULL, 16), 32);
}