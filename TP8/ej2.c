#include <stdio.h>
int main(void)
{
    int a = 257;
    void *p;
    printf("a: %d\n", a);//Imprime el valor de a
    p = &a;//Le asigno la direc de memoria donde esta guardo el primer byte de la variable
    *((char *) p) = 5;//Modifico solo el primer byte de la variable a, por que estoy accediendo como si fuese un char (1 byte) a una variable int(4 bytes)
    printf("a: %d\n", a);//a va a tomar el valor 261
    return 0;
}