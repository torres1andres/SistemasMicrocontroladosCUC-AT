/*
Integrantes: Andrés Torres
Ejercicio: Caudalímetro
Compilador usado: OnlineGDB (C Compiler)

Enunciado:
Se recibe información de un caudalímetro en formato {'caudal': VALOR}, 
donde VALOR es un número entre 00 y 99. 
El programa debe mostrar:
{'último': ULTIMO, 'mayor': MAYOR, 'menor': MENOR, 'promedio': PROMEDIO}
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
    // Simulación de datos recibidos por puerto serial
    const char *datos[] = {
        "{'caudal': 10}",
        "{'caudal': 1}",
        "{'caudal': 27}",
        "{'caudal': 105}", // inválido (fuera de rango)
        "{'dato': 50}",    // inválido (formato incorrecto)
        "{'caudal': 5}"
    };
    int n = sizeof(datos) / sizeof(datos[0]);

    int ultimo = 0, mayor = -1, menor = 101;
    int suma = 0, contador = 0;

    for (int i = 0; i < n; i++) {
        const char *mensaje = datos[i];

        // Verificar si el mensaje tiene el formato correcto
        if (strncmp(mensaje, "{'caudal':", 10) == 0 && mensaje[strlen(mensaje)-1] == '}') {
            // Extraer el valor numérico después de "{'caudal': "
            int valor = atoi(mensaje + 11);

            // Validar rango (0 - 99)
            if (valor >= 0 && valor <= 99) {
                ultimo = valor;
                if (valor > mayor) mayor = valor;
                if (valor < menor) menor = valor;
                suma += valor;
                contador++;

                // Calcular promedio
                double promedio = (double) suma / contador;

                // Imprimir resultado en formato JSON
                printf("{'último': %d, 'mayor': %d, 'menor': %d, 'promedio': %.2f}\n",
                       ultimo, mayor, menor, promedio);
            }
        }
    }

    return 0;
}
