#include "ej5.h"

int main(void)
{
    char *arr[]={"col", "Co", "catas"};
    qsort(arr, 3, sizeof(char*), orden_alfa);
    printWordList(arr, 3);
    return 0;
}

//Funciones
