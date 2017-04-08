# esp8266-managed

## Features
- Central configuration
- All functions accessible via [MQTT](http://mqtt.org/) (message format optimized for [OpenHab 2](http://www.openhab.org/))
- Firmware updates via configurable HTTP update server
- Support for 
  - Infrared sender
  - DHT11 temperature/humidity sensor
  - 433MHz sender (for switching wireless sockets)
  - Window contacts/motion sensors

## ToDo's
- Configure ESP via JSON string
- Create UI for managing & configuring ESPs and publishing such JSON string via MQTT (like [IBM Watson IoT Platform](https://developer.ibm.com/recipes/tutorials/run-an-esp8266arduino-as-a-iot-foundation-managed-device/), just free)

## Installation
You need python for building. First, clone repository and change into the cloned directory. May set your board in `platformio.ini`, then do
```
pip install -U platformio
git submodule update --init --recursive
platformio run -e default
```
        
    