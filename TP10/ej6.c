/*Escribir de manera recursiva una función que devuelve si un arreglo es capicúa
(es decir, sus elementos están espejados). El prototipo debe ser:
int is_capicua(int* p1, int *p2);
Siendo p1 un puntero al primer elemento de un arreglo y p2 uno al último*/
#include <stdio.h>
int is_capicua(int* p1, int *p2);
int main(int argc, char const *argv[])
{
    int arr[]={1,2,1};
    printf("%d\n", is_capicua(arr, arr+2));
    return 0;
}

int is_capicua(int* p1, int *p2){
    if(p1>=(p2-1)){
        if(*p1==*p2) return 1;
        else return 0;
    }
    else{
        if(*p1==*p2) return is_capicua(p1+1,p2-1);
        else return 0;
    }       
}

int is_capicua(int* p1, int* p2) {
    if (p1 >= p2) // ya nos cruzamos o nos tocamos → es capicúa
        return 1;

    if (*p1 != *p2)
        return 0;

    return is_capicua(p1 + 1, p2 - 1);
}