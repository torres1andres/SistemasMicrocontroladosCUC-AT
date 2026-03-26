#include "DHT11.h"

DHT11::DHT11(uint8_t pin) : _pin(pin) {
    pinMode(_pin, INPUT);
}

bool DHT11::read(float &temperature, float &humidity) {
    if (_readSensor()) {
        humidity    = _data[0] + _data[1] * 0.1f;
        temperature = _data[2] + _data[3] * 0.1f;
        return true;
    }
    return false;
}

bool DHT11::_waitForState(uint8_t state, uint32_t timeoutUs) {
    uint32_t start = micros();
    while (digitalRead(_pin) != state) {
        if (micros() - start > timeoutUs) return false;
    }
    return true;
}

bool DHT11::_readSensor() {
    memset(_data, 0, sizeof(_data));

    // --- Señal de inicio ---
    pinMode(_pin, OUTPUT);
    digitalWrite(_pin, LOW);
    delay(DHT_START_LOW_MS);
    digitalWrite(_pin, HIGH);
    delayMicroseconds(DHT_START_HIGH_US);
    pinMode(_pin, INPUT);

    // --- Respuesta del sensor ---
    if (!_waitForState(LOW,  DHT_TIMEOUT_US)) return false;
    if (!_waitForState(HIGH, DHT_TIMEOUT_US)) return false;
    if (!_waitForState(LOW,  DHT_TIMEOUT_US)) return false;

    // --- Lectura de 40 bits ---
    for (int i = 0; i < 40; i++) {
        if (!_waitForState(HIGH, 70)) return false;

        uint32_t highStart = micros();
        if (!_waitForState(LOW, DHT_TIMEOUT_US)) return false;
        uint32_t highDuration = micros() - highStart;

        uint8_t byteIndex = i / 8;
        uint8_t bitIndex  = 7 - (i % 8);

        if (highDuration > DHT_BIT_THRESHOLD) {
            _data[byteIndex] |= (1 << bitIndex);   // bit 1
        } else {
            _data[byteIndex] &= ~(1 << bitIndex);  // bit 0
        }
    }

    // --- Verificación de checksum ---
    uint8_t checksum = _data[0] + _data[1] + _data[2] + _data[3];
    return (checksum == _data[4]);
}
