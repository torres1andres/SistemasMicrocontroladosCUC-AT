
#include <Arduino.h>

int numero = 0;

void setup() {
  Serial.begin(115200); // Inicializa el puerto serial
  while(!Serial);       // Espera a que se abra el puerto serial
  Serial.println("Envía un número entero positivo:");
}

void loop() {
  if (Serial.available() > 0) {
    String entrada = Serial.readStringUntil('\n'); // Leer hasta salto de línea
    entrada.trim(); // Quita espacios y saltos de línea
    
    // Verificar que la entrada sea un número entero positivo
    if (entrada.length() > 0 && entrada.toInt() > 0) {
      numero = entrada.toInt();
      int cuadrado = 0;
      int impar = 1;
      
      // Sumar los primeros 'numero' números impares
      for (int i = 0; i < numero; i++) {
        cuadrado += impar;
        impar += 2;
      }
      
      Serial.print("El cuadrado de ");
      Serial.print(numero);
      Serial.print(" es: ");
      Serial.println(cuadrado);
    } else {
      // Ignorar entradas no válidas
      Serial.println("Entrada inválida, envía un número entero positivo.");
    }
  }
}
