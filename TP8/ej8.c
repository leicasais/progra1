#define MAX 100
#include <stdio.h>
void imprimo(char* opcion[2][MAX], int o,int p, char* parametro[MAX]);
int main(int argc, char *argv[])
{
    char* opcion[2][MAX];
    char* parametro[MAX];
    int o=0,p=0;
    for(int i=1; i<argc; i++){
        if (argv[i][0]=='-'){
            opcion[0][o]= &argv[i][1];
            opcion[1][o]= &argv[++i][0];
            o++;
        }
        else{
            parametro[p]=&argv[i][0];
            p++;
        }      
    }
    imprimo(opcion, o, p, parametro);
    return 0;
}

void imprimo(char* opcion[2][MAX], int o,int p, char* parametro[MAX]){
    for (int i = 0; i<o; i++){
        printf("Opcion %d: Clave: %s Valor: %s\n", i+1, opcion[0][i], opcion[1][i]);
    }
    for (int i=0; i<p; i++){
        printf("Parametro %d: %s\n", i+1,parametro[i]);
    }
}