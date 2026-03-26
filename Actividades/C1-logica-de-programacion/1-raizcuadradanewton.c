/*
Ejercicio:
De un número entero positivo que está guardado en una variable llamada NUMERO,
mostrar en pantalla su raíz cuadrada usando el método de Newton.

Integrantes:
- Andrés Torres

Compilador usado:
OnlineGDB
*/
#include <stdio.h>

// valor absoluto sin usar math.h
double absd(double v) { return (v <  0) ? -v : v; }

// Función: raíz cuadrada por Newton
double raizCuadradaNewton(int numero) {
    if (numero == 0) return 0.0;          // evita división por 0
    
    // Aproximación inicial:
    double x = (double)numero;
    double prev;
    const double precision = 1e-6;        // criterio de parada
    const int max_it = 1000;              // por si acaso, tope de iteraciones
    int it = 0;

    // Iteración de Newton: x_{n+1} = (x_n + N/x_n) / 2
    do {
        prev = x;
        x = 0.5 * (prev + numero / prev);
        it++;
    } while (absd(x - prev) > precision && it < max_it);

    return x;
}

int main(void) {
    int NUMERO = 256; // poner aca el valor a evaluar
    if (NUMERO < 0) return 0; // Número negativo: no hay raíz real, por ende, no imprimir nada

    double resultado = raizCuadradaNewton(NUMERO);

    // Salida tipo diccionario de Python
    printf("{'Número' : %d, 'Raíz cuadrada usando Newton' : %.3f}\n", NUMERO, resultado);
    return 0;
}
