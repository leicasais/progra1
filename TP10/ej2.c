/*Escribir un programa que produzca una serie de números pseudo-aleatorios en
punto flotante en los siguientes rangos:
• 0.0 - 1.0
• 0.0 - n, con n cualquier número en punto flotante.
• n - m, con n, m cualquier número en punto flotante.*/
#include <stdlib.h>
#include <time.h>
#include <stdio.h>

float rand_n_m(float n, float m);
float rand_0_1(void);
float rand_0_n(float n);

int main()
{
    srand(time(NULL));  // Semilla aleatoria, para que te de cda vez que se ejecute el programa num aleatorios. time(NULL) devuelve el número de segundos desde el 1 de enero de 1970 (época UNIX).
    float n = 5.0;
    float m = 10.0;

    printf("Número en [0.0, 1.0]: %f\n", rand_0_1());
    printf("Número en [0.0, %.2f]: %f\n", n, rand_0_n(n));
    printf("Número en [%.2f, %.2f]: %f\n", n, m, rand_n_m(n, m));

    return 0;
}

float rand_0_1(void){
    return (float)rand()/RAND_MAX;
}

float rand_0_n(float n){
    return rand_0_1()*n;
}

float rand_n_m(float n, float m){
    return rand_0_1()*(m-n)+n;//primero multiplico una proporcion q va del 0-1 por la distancia entre ambos puntos-> num esta entre 0-(m-n)-> le sumo n a cualquier num-> min n y max m
}