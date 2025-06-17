#include <stdlib.h>
#include <stdio.h>

double* eye (unsigned int n);
double** eye2 (unsigned int n);

int main(void)
{
    unsigned int num;
    scanf("%u", &num);
    double * m= eye(num);
    for (int i = 0; i < num; i++) {
        for (int j = 0; j < num; j++) {
            printf("%.1f", m[i * num + j]);
            if (j < num - 1) printf(", ");
        }
        printf("\n");
    }

}


double** eye2 (unsigned int n){
    double* f;
    double** m;

    if (!(m= (double**) calloc(n, sizeof(double*)))){
            printf("Hubo un error al usar calloc\n");
            exit(1);
        }
    for (int i=0; i<n;i++){
        if (!(f= (double*) calloc(n, sizeof(double)))){
            printf("Hubo un error al usar calloc\n");
            exit(1);
        }
        m[i]= f;
        m[i][i]=1;
    }
    
    return m;

    
}

double* eye (unsigned int n){
    double* m;

    if (!(m= (double*)calloc(n*n, sizeof(double)))){
        printf("Hubo un error al usar calloc\n");
        exit(1);
    }
    for (int i=0; i<(n*n);){
        m[i]=1;
        i+=(n+1);
    }
    return m;
    
}