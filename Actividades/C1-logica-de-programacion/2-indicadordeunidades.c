/*
Ejercicio:
Una variable llamada NUMERO contiene un entero de 4 dígitos 
(mayor o igual a 1000 y menor o igual 9999).

Integrantes:
- Andrés Torres

Compilador usado:
OnlineGDB
*/
#include <stdio.h>

int main() {
    int NUMERO = 4825;  // Cambiar este valor para probar otros casos

    // Verificar rango
    if (NUMERO < 1000 || NUMERO > 9999) {
        return 0; // No ejecutar nada
    }

    // Descomposición del número
    int unidadMil = NUMERO / 1000;
    int centena   = (NUMERO / 100) % 10;
    int decena    = (NUMERO / 10) % 10;
    int unidad    = NUMERO % 10;

    // Mostrar en formato
    printf("{'Número' : %d, 'Unidad' : %d, 'Decena' : %d, 'Centena' : %d, 'Unidad de mil' : %d}\n",
           NUMERO, unidad, decena, centena, unidadMil);

    return 0;
}
