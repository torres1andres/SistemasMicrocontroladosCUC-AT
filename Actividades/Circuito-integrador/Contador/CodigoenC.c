/*
Ejercicio:
Circuito Integrador

Integrantes:
- Andrés Torres

Compilador usado:
OnlineGDB
*/

#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/gpio.h"
#include "esp_system.h"

// -------- CONFIGURACIÓN --------
#define PIN_INCREMENTA  14   // Pulsador incrementar
#define PIN_DECREMENTA  27   // Pulsador decrementar
#define PIN_LED         2    // LED (puede ser el interno)

// Variable global
static int CONTEO = 0;

// -------- FUNCIONES AUXILIARES --------
void imprimirConteo() {
    printf("{'contador': %d}\n", CONTEO);
}

// -------- TAREA PRINCIPAL --------
void app_main(void) {
    // Configuración de pines
    gpio_reset_pin(PIN_INCREMENTA);
    gpio_set_direction(PIN_INCREMENTA, GPIO_MODE_INPUT);
    gpio_set_pull_mode(PIN_INCREMENTA, GPIO_PULLUP_ONLY);

    gpio_reset_pin(PIN_DECREMENTA);
    gpio_set_direction(PIN_DECREMENTA, GPIO_MODE_INPUT);
    gpio_set_pull_mode(PIN_DECREMENTA, GPIO_PULLUP_ONLY);

    gpio_reset_pin(PIN_LED);
    gpio_set_direction(PIN_LED, GPIO_MODE_OUTPUT);

    printf("Sistema iniciado...\n");

    while (1) {
        // Pulsador incrementar
        if (gpio_get_level(PIN_INCREMENTA) == 0) {
            if (CONTEO < 20) {
                CONTEO++;
            }
            imprimirConteo();
            vTaskDelay(pdMS_TO_TICKS(250));  // debounce
        }

        // Pulsador decrementar
        if (gpio_get_level(PIN_DECREMENTA) == 0) {
            if (CONTEO > 0) {
                CONTEO--;
            }
            imprimirConteo();
            vTaskDelay(pdMS_TO_TICKS(250));  // debounce
        }

        // LED en CONTEO == 10
        if (CONTEO == 10) {
            gpio_set_level(PIN_LED, 1);
            vTaskDelay(pdMS_TO_TICKS(4000));  // 4 seg encendido
            gpio_set_level(PIN_LED, 0);
        }

        vTaskDelay(pdMS_TO_TICKS(50)); // Pequeño delay para evitar rebotes
    }
}
