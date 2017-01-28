#include "main.h"

void setup() {
    Serial.begin(115200);

    wifi_setup();
    mqtt_setup();
    ir_setup();
    tx433mhz_setup();
    contacts_setup();
}

void loop() {
    mqtt_loop();
}
