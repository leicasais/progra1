#include <stdlib.h>
#include <stdio.h>
int creciente(const void*a, const void*b);
void printIntArray(int arr[], int size);
int decreciente(const void*a, const void*b);
int main(void)
{
    int list[]={1,3,4,5,2};
    printIntArray(list, sizeof(list)/sizeof(int));
    qsort(list, sizeof(list)/sizeof(int), sizeof(int), creciente);
    printIntArray(list, sizeof(list)/sizeof(int));
    int (*p_decreciente) (const void*, const void*)= decreciente;
    qsort(list, sizeof(list)/sizeof(int), sizeof(int), p_decreciente);
    printIntArray(list, sizeof(list)/sizeof(int));
    return 0;
}

//funciones

int creciente(const void*a, const void*b){
    return *((int*)a)-*((int*)b);
}
int decreciente(const void*a, const void*b){
    return *((int*)b)-*((int*)a);
}
void printIntArray(int arr[], int size) {
    printf("[");
    for (int i = 0; i < size; i++) {
        printf("%d", arr[i]);
        if (i < size - 1) printf(", ");
    }
    printf("]\n");
}