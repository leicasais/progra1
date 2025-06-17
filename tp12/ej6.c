#include <stdio.h>
#include <stdlib.h>//No estaba en el codigo original

int main(void){
    int dado,i;
    for (i=1; i<=5; ++i)//Se repite 5 veces, una vez para cda dado
        printf("%d\n", rand()%6 + 1);//elije un numero random del 1 al 6
    return 0;
}//Esta bien escrito, eceptuando que falta agregar la libreria stdlib.h, sin la incorporacion de esta libreria no se puede usar la funcion rand()
