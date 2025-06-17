#include <stdio.h>
int main(void)
{
    int a = 5;
    void *p = &a;
    void **pp = &p;
    printf("pp: %p\n", pp);//Imprime la direc de memoria de p
    printf("*pp: %p\n", *pp);//Imprime ladireccion de memoria de a
    printf("**pp: %d\n", **(int**)pp);//Necesita ser casteado explicitamente para poder imprimir el valor que guarda a, sino no sabe como acceder al dato de un puntero del tipo void
    return 0;
}