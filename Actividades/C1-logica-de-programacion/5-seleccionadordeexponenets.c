/*
Ejercicio:
Emular el comportamiento del script "Seleccionar exponentes de un grupo".

Integrantes:
- Andrés Torres

Compilador usado:
OnlineGDB
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int NUMERO = 10;      // Número total de integrantes en el grupo
    int CANTIDAD = 3;     // Cantidad de exponentes a elegir

    
    if (CANTIDAD > NUMERO || NUMERO <= 0 || CANTIDAD <= 0) { // Validar que no se pidan más exponentes que integrantes
        return 0; // no mostrar nada si no se cumple la condición
    }

    int ORDEN[100];  // arreglo para guardar el orden 
    int usados[100] = {0}; // arreglo auxiliar para no repetir exponentes

    srand(time(NULL)); // inicializar generador de números aleatorios

    for (int i = 0; i < CANTIDAD; i++) {
        int elegido;
        do {
            elegido = rand() % NUMERO + 1; // número aleatorio entre 1 y NUMERO
        } while (usados[elegido]); // repetir si ya fue seleccionado

        ORDEN[i] = elegido;   // guardar en el orden
        usados[elegido] = 1;  // marcar como usado
    }

    // Mostrar resultado
    printf("{'Número de integrantes en el grupo' : %d, 'Cantidad de exponentes' : %d, 'Orden de exponentes' : [", NUMERO, CANTIDAD);

    for (int i = 0; i < CANTIDAD; i++) {
        printf("%d", ORDEN[i]);
        if (i < CANTIDAD - 1) {
            printf(", ");
        }
    }

    printf("]}\n");

    return 0;
}