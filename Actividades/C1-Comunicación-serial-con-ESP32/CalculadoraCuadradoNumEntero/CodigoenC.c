/*
Integrantes: Andrés Torres
Ejercicio: Caudalímetro
Compilador usado: OnlineGDB (C Compiler)

Enunciado:
Se puede calcular el cuadrado de un número N al sumar los primeros N números 
impares. Si se recibe algo diferente a un número entero positivo mayor 
a cero se debe ignorar.
*/

#include <stdio.h>
#include <stdlib.h>

int main() {
    char entrada[100];
    int numero;

    printf("Envía un número entero positivo: ");
    
    // Leer la entrada como cadena
    if (fgets(entrada, sizeof(entrada), stdin) != NULL) {
        // Convertir la entrada a entero
        numero = atoi(entrada);

        // Verificar que sea un entero positivo
        if (numero > 0) {
            int cuadrado = 0;
            int impar = 1;

            // Sumar los primeros 'numero' números impares
            for (int i = 0; i < numero; i++) {
                cuadrado += impar;
                impar += 2;
            }

            printf("El cuadrado de %d es: %d\n", numero, cuadrado);
        } else {
            printf("Entrada inválida, envía un número entero positivo.\n");
        }
    } else {
        printf("Error al leer la entrada.\n");
    }

    return 0;
}
