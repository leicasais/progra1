/*Crear un arreglo de alumnos, representados por una estructura que almacene
nombre, apellido y nota promedio en tres campos distintos. Luego ordenar el
arreglo usando la función qsort(), de manera que queden ordenados por nota en
orden decreciente, si comparten la misma nota por apellido en orden alfabético, y
si tienen la misma nota y el mismo apellido ordenados por nombre en orden
alfabético*/
#include "ej5.h"
void llenar_palabras(char** p, char*dto);
void llenar_dtos(char**pnomb, char*nomb,char**pap, char*ap, int*pnot, int not);
typedef struct{
    char* nombre;
    char* spellido;
    int nota;
}alumnos_t;

int main(void){
    alumnos_t al1, al2,al3;
    llenar_dtos(&al1.nombre, "Juan", &al1.spellido, "casais", &al1.nota, 5);
    llenar_dtos(&al2.nombre, "juan", &al2.spellido, "CasaIS", &al2.nota, 7);
    llenar_dtos(&al3.nombre, "ARIEL", &al3.spellido, "Casais", &al3.nota, 7);
    alumnos_t alumnos[]={al1,al2,al3};
    int val;
    for(int j=0;j<((sizeof(alumnos)/sizeof(alumnos_t))-1);j++){
        for(int i=0;i<((sizeof(alumnos)/sizeof(alumnos_t))-1);i++){
            val=orden_alfa((const void*)&alumnos[i].spellido, (const void*)&alumnos[i+1].spellido);
            if (val==0){
                val=alumnos[i].nota-alumnos[i+1].nota;
                if (val>0)
                {
                    alumnos_t c=alumnos[i+1];
                    alumnos[i+1]=alumnos[i];
                    alumnos[i]=c;
                }
                else if (val==0)
                {
                    val=orden_alfa((const void*)&alumnos[i].nombre, (const void*)&alumnos[i+1].nombre);
                    if(val>0){
                        alumnos_t c=alumnos[i+1];
                        alumnos[i+1]=alumnos[i];
                        alumnos[i]=c;
                    }
                }
            }
            else if(val>0){
                alumnos_t c=alumnos[i+1];
                alumnos[i+1]=alumnos[i];
                alumnos[i]=c;
            }
        }
    }


    free(al1.nombre);
    free(al1.spellido);
    free(al2.nombre);
    free(al2.spellido);
    return 0;
}

//Funciones
void llenar_palabras(char** p, char*dto){
    int cant=0;
    for(int i=0;dto[i];i++) cant++;
    *p=(char*)malloc(sizeof(char)*cant);
    for(int i=0;dto[i];i++) p[0][i]=dto[i];
}
void llenar_dtos(char**pnomb, char*nomb,char**pap, char*ap, int*pnot, int not){
    llenar_palabras(pnomb,nomb);
    llenar_palabras(pap,ap);
    *pnot=not;
}

