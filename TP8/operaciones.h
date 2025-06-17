#ifndef EJ7_H
#define EJ7_H
//libs
#include <stdlib.h>
#include <stdio.h>

//Macros
#define MAX 10

//Prototipos
float suma (float x, float y);
float resta (float x, float y);
float mult (float x, float y);
float divv (float x, float y);
float pot(float x, float y);
void add_operation(char op, float (*p) (float, float));
void get_input(float*x, float*y, char*op);
float calc_res(float x, float y, char op);


#endif