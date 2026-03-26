/*
Ejercicio:
Crear un programa que calcule la sumatoria y productoria de los números 
enteros en el rango dado por INICIO y FIN. 

Integrantes:
- Andrés Torres

Compilador usado:
OnlineGDB
*/
#include <stdio.h>

int main() {
    int INICIO = 3;   // Cambiar para probar
    int FIN = 15;      // Cambiar para probar
    int SUMATORIA = 0;
    int PRODUCTORIA = 1;

    // Verificar condición
    if (FIN > INICIO) {
        for (int i = INICIO; i <= FIN; i++) {
            SUMATORIA += i;      // acumula la suma
            PRODUCTORIA *= i;    // acumula el producto
        }

        // Mostrar resultado en formato
        printf("{'Número de inicio' : %d, 'Número de fin' : %d, 'Sumatoria' : %d, 'Productoria' : %d}\n",
               INICIO, FIN, SUMATORIA, PRODUCTORIA);
    }

    return 0;
}