#include <Arduino.h>

// Pines de pulsadores y LED
const int pinIncremento = 4;
const int pinDecremento = 5;
const int pinLed = 2;

int conteo = 0;
bool ledEncendido = false;
unsigned long tiempoEncendido = 0;

void imprimirConteo() {
  Serial.print("{'contador': ");
  Serial.print(conteo);
  Serial.println("}");
}

void setup() {
  pinMode(pinIncremento, INPUT_PULLUP);
  pinMode(pinDecremento, INPUT_PULLUP);
  pinMode(pinLed, OUTPUT);

  Serial.begin(115200);
  Serial.println("Contador iniciado...");
}

void loop() {
  // Leer pulsadores físicos
  if (digitalRead(pinIncremento) == LOW) {
    if (conteo < 20) conteo++;
    imprimirConteo();
    delay(300); // antirrebote
  }

  if (digitalRead(pinDecremento) == LOW) {
    if (conteo > 0) conteo--;
    imprimirConteo();
    delay(300); // antirrebote
  }

  // Leer comandos desde el monitor serial
  if (Serial.available()) {
    char comando = Serial.read();
    if (comando == '+') {
      if (conteo < 20) conteo++;
      imprimirConteo();
    } else if (comando == '-') {
      if (conteo > 0) conteo--;
      imprimirConteo();
    }
  }

  // Si llega a 10 → encender LED 4s sin bloquear
  if (conteo == 10 && !ledEncendido) {
    digitalWrite(pinLed, HIGH);
    ledEncendido = true;
    tiempoEncendido = millis(); // guardar el momento en que se encendió
  }

  // Verificar si ya pasaron los 4s
  if (ledEncendido && millis() - tiempoEncendido >= 4000) {
    digitalWrite(pinLed, LOW);
    ledEncendido = false;
  }
}

