#include <Arduino.h>

// Variables globales
int ultimo = -1;
int mayor = -1;
int menor = 101;
long suma = 0;
int contador = 0;

void setup() {
  Serial.begin(115200); // Velocidad típica para ESP32
  Serial.println("Caudalímetro iniciado...");
}

void loop() {
  // Revisar si llegó algo por el puerto serial
  if (Serial.available()) {
    String input = Serial.readStringUntil('\n'); // Leer hasta el salto de línea

    // Verificar que el formato empiece con {"caudal":
    if (input.startsWith("{'caudal':") && input.endsWith("}")) {
      // Extraer el valor
      int inicio = input.indexOf(":") + 1;
      int fin = input.indexOf("}");
      String valorStr = input.substring(inicio, fin);
      valorStr.trim(); // Quitar espacios

      // Convertir a número
      int valor = valorStr.toInt();

      // Validar que esté en el rango 0–99
      if (valor >= 0 && valor <= 99) {
        ultimo = valor;
        if (mayor == -1 || valor > mayor) mayor = valor;
        if (menor == 101 || valor < menor) menor = valor;

        suma += valor;
        contador++;

        float promedio = (float)suma / contador;

        // Imprimir el resultado en el formato pedido
        Serial.print("{'último': ");
        Serial.print(ultimo);
        Serial.print(", 'mayor': ");
        Serial.print(mayor);
        Serial.print(", 'menor': ");
        Serial.print(menor);
        Serial.print(", 'promedio': ");
        Serial.print(promedio, 2); // 2 decimales
        Serial.println("}");
      }
    }
  }
}
