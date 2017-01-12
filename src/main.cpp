#include "main.h"

void setup() {
    Serial.begin(115200);
    setup_wifi();
    setup_mqtt();
}

void loop() {
    mqtt_loop();
}
