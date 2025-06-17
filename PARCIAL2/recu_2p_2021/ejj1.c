#include <stdlib.h>
char* mundo(int alto, int ancho){
    char* arr=malloc(alto*ancho*sizeof(char));
    for(int i=0; i<(alto*ancho); i++){
            arr[i]=rand()%2;
    }
    return arr;
}

char* mundo2(int alto, int ancho){
    char** arr=malloc(alto*sizeof(*arr));//Reservo alto lugares de memoria para puteros a char y guardo la direcion de memoria del primer puntero a char en arr
    for(int i=0; i<alto; i++){//Asigncion para cada puntero a char
        arr[i]=malloc(ancho*sizeof(char));//reservo ancho lugares de chars y guardo la direccion al primer puntero de la zona de chars reservados
        for(int j=0;j<ancho;j++){
            arr[i][j]=rand()%2;//reservo ancho lugares de chars 
        }
    }
    return arr;
}