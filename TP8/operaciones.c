#include "operaciones.h"
extern char operandos[MAX];
extern float (*p_fun[MAX]) (float, float);
//funciones

float suma (float x, float y){
    return x+y;
}
float resta (float x, float y){
    return x-y;
} 
float mult (float x, float y){
    return x*y;
}
float divv (float x, float y){
    return x/y;
}
float pot(float x, float y){
    float rta=1;
    for(int i=0; i<(int)y; i++){
        rta*=x;
    }
    return rta;
}
void add_operation(char op, float (*p) (float, float)){
    static int cant;
    operandos[cant]=op;
    p_fun[cant]=p;
    cant++;
}

void get_input(float*x, float*y, char*op){
    printf("Ingrese el primer numero: ");
    scanf("%f", x);
    printf("Ingrese el operando: ");
    scanf(" %c", op);
    printf("Ingrese el segundo numero: ");
    scanf("%f", y);

}
float calc_res(float x, float y, char op){
    int i;
    for(i=0; i<MAX; i++){
        if(operandos[i]==op) break;
    }
    return p_fun[i](x,y);
}