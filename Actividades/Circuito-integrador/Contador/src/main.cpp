#include <Arduino.h>

// --------- CONFIGURACIÓN ---------
// Descomenta SOLO UNO de los modos
#define MODO_SERIAL
// #define MODO_SERIAL
// #define MODO_PULSADORES

// Pines para los pulsadores y LED
const int pinIncrementa = 14;   // GPIO14 
const int pinDecrementa = 27;   // GPIO27 
const int pinLed = 2;           // LED integrado (GPIO2)

// Variable de conteo
int CONTEO = 0;

// --------- FUNCIONES AUXILIARES ---------
void imprimirConteo() {
  Serial.print("{'contador': ");
  Serial.print(CONTEO);
  Serial.println("}");
}


void setup() {
  Serial.begin(115200);

#ifdef MODO_PULSADORES
  pinMode(pinIncrementa, INPUT_PULLUP); // Pulsador con resistencia interna
  pinMode(pinDecrementa, INPUT_PULLUP);
#endif

  pinMode(pinLed, OUTPUT);
  digitalWrite(pinLed, LOW);

  Serial.println("Sistema iniciado...");
}

void loop() {
#ifdef MODO_PULSADORES
  // ---- LECTURA DE PULSADORES ----
  if (digitalRead(pinIncrementa) == LOW) {   // Pulsador presionado
    if (CONTEO < 20) {
      CONTEO++;
    }
    imprimirConteo();
    delay(250); // Anti-rebote
  }

  if (digitalRead(pinDecrementa) == LOW) {
    if (CONTEO > 0) {
      CONTEO--;
    }
    imprimirConteo();
    delay(250); // Anti-rebote
  }
#endif

#ifdef MODO_SERIAL
  // ---- LECTURA DESDE TECLADO SERIAL ----
  if (Serial.available() > 0) {
    char tecla = Serial.read();
    if (tecla == '+') {
      if (CONTEO < 20) {
        CONTEO++;
      }
      imprimirConteo();
    } else if (tecla == '-') {
      if (CONTEO > 0) {
        CONTEO--;
      }
      imprimirConteo();
    }
  }
#endif

  // ---- CONTROL DEL LED ----
  if (CONTEO == 10) {
    digitalWrite(pinLed, HIGH);
    delay(4000); // LED encendido por 4 segundos
    digitalWrite(pinLed, LOW);
  }
}

