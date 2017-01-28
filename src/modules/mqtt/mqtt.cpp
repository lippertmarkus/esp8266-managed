#include "mqtt.h"

WiFiClient espClient;
PubSubClient mqttClient(espClient);

void mqtt_setup() {
    mqttClient.setServer(mqtt_server, mqtt_port);
    mqttClient.setCallback(mqtt_callback);
}

void mqtt_loop() {
    if (!mqttClient.connected()) {
        mqtt_reconnect();
    }
    mqttClient.loop();

    mqtt_publish();
}

void mqtt_callback(char* intopic, byte* payload, unsigned int length) {
    Serial.print("Message arrived [");
    Serial.print(intopic);
    Serial.print("] ");

    String topic = intopic;
    String message = "";

    for (int i = 0; i < length; i++) {
        message.concat((char)payload[i]);
    }
    Serial.println(message);

    system_mqtt_callback(topic, message);
    tx433mhz_mqtt_callback(topic, message);
    ir_mqtt_callback(topic, message);
    // TODO
}

void mqtt_reconnect() {
    // Loop until we're reconnected
    while (!mqttClient.connected()) {
        Serial.print("Attempting MQTT connection...");

        String hostname = WiFi.hostname();
        hostname.toLowerCase();

        // Attempt to connect
        if (mqttClient.connect(hostname.c_str())) {
            Serial.println("connected");

            mqtt_subscribe();
        } else {
            Serial.print("failed, rc=");
            Serial.print(mqttClient.state());
            Serial.println(" try again in 5 seconds");
            // Wait 5 seconds before retrying
            delay(5000);
        }
    }
}

void mqtt_subscribe() {
    system_subscribe(mqttClient);
    tx433mhz_subscribe(mqttClient);
    ir_subscribe(mqttClient);
    // TODO
}

void mqtt_publish() {
    dht11_publish(mqttClient);
    contacts_publish(mqttClient);
    // TODO
}