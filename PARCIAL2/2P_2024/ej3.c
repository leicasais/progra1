#include<stdio.h>
int main(int argc, char const *argv[])
{
    printf("%ld, %ld\n", sizeof(int), sizeof(int*));
    //Decir que imprime x+1
    char *x[11];// arr de 11 punteros a char
    int x[7][3];// arr de 7 arr de int. Desplazamiento por elem-> 3*4=0xC
    void **x;//No se puede hacer por que es un puntero a void y el compilador no sabe cuantos bytes= 1 elemento
    const float (*x) [5];// puntero a un arr de 5 floats const. 4*5=0x14
    return 0;
}
