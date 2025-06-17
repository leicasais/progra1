/*Escribir un programa que dado un número ingresado por el usuario, cree un arreglo
que guarde exactamente esa cantidad de elementos enteros utilizando malloc o
calloc, reciba del usuario esa cantidad de números en el arreglo creado, y luego los
imprima.*/
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int num;
    printf("Ingrese la cantida de numeros\n");
    scanf("%d",&num);
    int *p=(int*) malloc(num*sizeof(int));
    for(int i=0; i<num;i++){
        printf("Ingresar el numero :\n");
        scanf("%d", &p[i]);
    }
    for(int i=0; i<num;i++){
        printf(" %d\n", p[i]);
    }
    return 0;
}
