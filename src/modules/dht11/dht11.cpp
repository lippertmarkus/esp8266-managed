#include "dht11.h"

SimpleDHT11 dht11;
unsigned long previousMillis = 0;

void dht11_publish(PubSubClient mqtt_client) {
    unsigned long currentMillis = millis();

    if (currentMillis - previousMillis >= dht11_publish_cycle) {
        previousMillis = currentMillis;

        dht11_publishSensorData(mqtt_client);
    }
}

void dht11_publishSensorData(PubSubClient mqtt_client) {
    int temp;
    int hum;

    byte temperature = 0;
    byte humidity = 0;
    if (dht11.read(dht11_pin, &temperature, &humidity, NULL)) {
        Serial.println("Read DHT11 failed.");
        return;
    }

    temp = (int)temperature;
    hum = (int)humidity;

    Serial.print("Publishing temperature ");
    Serial.print(temp);
    Serial.print("°C to ");
    Serial.println(dht11_temperature_topic);
    mqtt_client.publish(dht11_temperature_topic, String(temp).c_str(), true);

    Serial.print("Publishing humidty ");
    Serial.print(hum);
    Serial.print("% to ");
    Serial.println(dht11_humidity_topic);
    mqtt_client.publish(dht11_humidity_topic, String(hum).c_str(), true);
}