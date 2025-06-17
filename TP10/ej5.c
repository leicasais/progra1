/*Escribir el código de la función recursiva dec2bin() que recibe un número como
argumento y lo imprime en la pantalla en binario*/
#include <stdio.h>
void dec2bin(const unsigned int num);
void dec22bin(const unsigned int num);
int pot(int num,int rep);
void dec222bin(unsigned int n);
int main(void)
{
    dec222bin(0);
    return 0;
}

void dec22bin(const unsigned int num){
    if(num==0){
        printf("0");
    }
    else{
        dec22bin(num/2);
        printf("%d", num%2);
    }
}
void dec222bin(unsigned int n)
{
    if (n > 1)          // seguir dividiendo mientras queden bits “a la izquierda”
        dec222bin(n >> 1);   // desplazar (dividir por 2) y llamar recursivamente

    putchar('0' + (n & 1));  // imprimir el bit menos significativo ultimo
}

void dec2bin(const unsigned int num){
    static int aux=0;
    if(num==0){
        printf("%d\n",aux);
    }
    else{
        int i;
        for(i=0;aux&(1<<i);i++) aux-=pot(10,i);
        aux+=pot(10,i);
        dec2bin(num-1);

    }
}
int pot(int num,int rep){
    int rta=1;
    for(int i=0;i<rep;i++){
        rta*=num;
    }
    return rta;
}