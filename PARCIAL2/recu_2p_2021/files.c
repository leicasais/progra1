/*
#include <stdlib.h>
Fopen(FILE *, 'w'); Devuelve un puntero al arch que permite escribir en el archivo. Si el arch no exite entonces creaun arch y devuelve el puntero al nuevo arch creado
Fopen(FILE *, 'r'); Devuelve un puntero al arch que permite solo leer en el archivo. Si el arch no exite entonces devuelve el puntero NULL
*/
#include<stdlib.h>
typedef struct nodo{
    int data;
    struct nodo* pNext;
}nodo_t;
int listAdd(nodo_t* first, int newData);

int main(void)
{   
    nodo_t* primer=calloc(1,sizeof(nodo_t));
    primer->data=1;
    primer->pNext=NULL;
    listAdd(primer, 4);
    listAdd(primer, 6);
    listAdd(primer, 7);
    
    free(primer->pNext->pNext);
    free(primer->pNext);
    free(primer);

    return 0;
}

int listAdd(nodo_t* first, int newData){
    nodo_t* pUlt=first;
    if(first){
        while(pUlt->pNext){
            pUlt=pUlt->pNext;
        }
        pUlt->pNext=calloc(1,sizeof(nodo_t));
        pUlt->pNext->data=newData;
        pUlt->pNext->pNext=NULL;
        if(!(pUlt->pNext)){
            return 0;
        }
        return 1;
    }
    else{
        return 0;//Error, con los argumentos pedidos no puedo guardar la direc directamente en first desde la funcion
    }
}