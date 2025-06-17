#ifndef EJ8_H
#define EJ8_H
//libs
#include <stdlib.h>
#include <stdio.h>

//Prototipos
void printIntArray(int arr[], int size);
void printWordList(char* words[], int size);
char mayus(char a);
char is_alfa(char a);
int orden_alfa(const void *ppa,const void *ppb);

//Funciones 
int orden_alfa(const void *ppa, const void *ppb){
    char *pa=*((char**)ppa);
    char *pb=*((char**)ppb);
    char a=*pa;
    char b=*pb;
    while(*pa && *pb){
        a=mayus(*pa);
        b=mayus(*pb);
        if(a-b){
            break;
        }
        pa++;
        pb++;
    }
    return a-b;
}
void printIntArray(int arr[], int size) {
    printf("[");
    for (int i = 0; i < size; i++) {
        printf("%d", arr[i]);
        if (i < size - 1) printf(", ");
    }
    printf("]\n");
}
void printWordList(char* words[], int size) {
    printf("[");
    for (int i = 0; i < size; i++) {
        printf("\"%s\"", words[i]);
        if (i < size - 1) printf(", ");
    }
    printf("]\n");
}
char mayus(char a){
    if (a>='a' && a<='z'){
        return a+'A'-'a';
    }
    return a;
}
char is_alfa(char a){
    if ((a>='A' && a<='Z')||(a>='a' && a<='z')){
        return 1;
    }
    return 0;
}

#endif
