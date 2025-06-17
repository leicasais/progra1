
#include"operaciones.h"

char operandos[MAX];
float (* p_fun[MAX]) (float, float);

int main(void){
    add_operation('+', suma);
    add_operation('-', resta);
    add_operation('*', mult);
    add_operation('%', divv);
    add_operation('^', pot);

    float x, y;
    char op;
    get_input(&x, &y, &op);
    printf("El reesultado final es: %f\n", calc_res(x, y, op));
    return 0;
}