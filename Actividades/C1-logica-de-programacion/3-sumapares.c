/*
Ejercicio:
Desarrollar un programa que calcule y muestre en pantalla la suma de los 
números enteros pares almacenados en un rango de números enteros definido por 
variables llamadas INICIO y FIN.

Integrantes:
- Andrés Torres

Compilador usado:
OnlineGDB
*/
#include <stdio.h>

int main() {
    int INICIO = 3;   // Cambiar este valor para probar
    int FIN = 15;     // Cambiar este valor para probar
    int SUMATORIA = 0;

    // condicion
    if (INICIO > 0 && FIN > INICIO) {
        
        for (int i = INICIO; i <= FIN; i++) { // Recorrer desde INICIO hasta FIN
            if (i % 2 == 0) {   // Solo si es par
                SUMATORIA += i;
            }
        }

        // Mostrar resultado en formato
        printf("{'Número de inicio' : %d, 'Número de fin' : %d, 'Sumatoria' : %d}\n", INICIO, FIN, SUMATORIA);
    }

    return 0;
}