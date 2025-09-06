/*
Ejercicio:
Emular el comportamiento del script :
"Tabla de verdad basada en número de identificación"

Integrantes:
- Andrés Torres

Compilador usado:
OnlineGDB
*/
#include <stdio.h>

int main() {
    unsigned int numero = 1042247880;  // ejemplo de número de identificación
    int bits[16] = {0};         // arreglo que guarda hasta 16 bits (salida Q)

    // Validar número (solo positivos)
    if (numero < 0) {
        return 0; // no mostrar nada si es inválido
    }

    // Extraer los bits del número en binario
    for (int i = 15; i >= 0; i--) {
        bits[15 - i] = (numero >> i) & 1; // de MSB a LSB
    }

    // Mostrar la tabla de verdad
    printf("Tabla de verdad basada en el número: %u\n", numero);
    printf("A B C D | Q\n");
    printf("---------------\n");

    for (int fila = 0; fila < 16; fila++) {
        int A = (fila >> 3) & 1;
        int B = (fila >> 2) & 1;
        int C = (fila >> 1) & 1;
        int D = (fila >> 0) & 1;

        printf("%d %d %d %d | %d\n", A, B, C, D, bits[fila]);
    }

    return 0;
}