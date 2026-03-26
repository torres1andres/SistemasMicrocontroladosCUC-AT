#include "DHT11.h"

const uint8_t  DHT_PIN      = 2;
const uint16_t INTERVALO_MS = 2000;

DHT11 sensor(DHT_PIN);

void setup() {
    Serial.begin(9600);
    Serial.println("Iniciando DHT11...");
    delay(2000); // Espera de estabilización al encender
}

void loop() {
    float temperatura = 0.0f;
    float humedad     = 0.0f;

    if (sensor.read(temperatura, humedad)) {
        Serial.print("Temperatura : ");
        Serial.print(temperatura, 1);
        Serial.println(" C");

        Serial.print("Humedad     : ");
        Serial.print(humedad, 1);
        Serial.println(" %RH");
    } else {
        // Verificar conexión y resistencia pull-up (5kΩ entre DATA y VDD)
        Serial.println("[ERROR] Fallo en la lectura.");
    }

    Serial.println("-----------------------------");
    delay(INTERVALO_MS);
}
