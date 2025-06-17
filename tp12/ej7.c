#include <stdio.h>
void muestra(void* p);
int main(void)
{
    int mat[3][5] = {{0, 1, 2, 3, 4},{-5, -6, -7, -8, -9},{5, 6, 7, 8, 9}};// creo una matriz de ints
    muestra(mat+1+1/2);//mat+1+0, mat[1], le paso el arreglo numero 1 de la matriz = {-5, -6, -7, -8, -9}
    return 0;
}
void muestra(void* p)
{
    printf("%d\n", *((int*)p+2)+3); // *((int*)p+2)+3 = *(mat[1][2])+3 = -7+3 = -4
}