#ifndef DHT11_H
#define DHT11_H

#include <Arduino.h>

// Constantes del protocolo según datasheet
const uint16_t DHT_START_LOW_MS  = 20;
const uint8_t  DHT_START_HIGH_US = 30;
const uint8_t  DHT_TIMEOUT_US    = 100;
const uint8_t  DHT_BIT_THRESHOLD = 40;

class DHT11 {
public:
    DHT11(uint8_t pin);
    bool read(float &temperature, float &humidity);

private:
    uint8_t _pin;
    uint8_t _data[5];

    bool _readSensor();
    bool _waitForState(uint8_t state, uint32_t timeoutUs);
};

#endif
