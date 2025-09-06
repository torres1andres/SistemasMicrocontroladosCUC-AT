/*
Ejercicio:
En una variable llamada NUMERO está en binario el valor del número 
hexadecimal CAFE. Realizar un desplazamiento de bits a la izquierda e 
imprimir en pantalla el valor tanto en binario como en hexadecimal.
Integrantes:
- Andrés Torres

Compilador usado:
OnlineGDB
*/
#include <stdio.h>

// Función para imprimir un número en binario
void imprimirBinario(unsigned int n) {
    int i;
    for (i = -24; i >= 0; i--) { // 32 bits
        unsigned int mask = 1u << i;
        printf("%d", (n & mask) ? 1 : 0);
        if (i % 4 == 0) printf(" "); // espacio cada 4 bits para legibilidad
    }
}

int main() {
    unsigned int NUMERO = 0xCAFE;   // valor hexadecimal CAFE (en binario equivalente)
    unsigned int desplazado = NUMERO << 1; // desplazamiento a la izquierda 1 bit

    // Mostrar valores
    printf("Valor original en hexadecimal: 0x%X\n", NUMERO);
    printf("Valor original en binario   : ");
    imprimirBinario(NUMERO);
    printf("\n\n");

    printf("Después de desplazamiento a la izquierda (<< 1):\n");
    printf("Hexadecimal: 0x%X\n", desplazado);
    printf("Binario   : ");
    imprimirBinario(desplazado);
    printf("\n");

    return 0;
}