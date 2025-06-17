#include <stdlib.h>
typedef struct{
    double *vec;
    int len;
}vecgen_t;

int removeElem(vecgen_t* p, int ind);
int compLargo(const void* p1, const void* p2);
int main(void){
    vecgen_t arr[4];
    for(int i=0;i<sizeof(arr)/sizeof(vecgen_t);i++ ){
        (arr+i)->len=4;
        (arr+i)->vec=malloc(sizeof(double)*((arr+i)->len));
        (arr+i)->vec[0]=((double)rand()/RAND_MAX)*8-4;
        (arr+i)->vec[1]=((double)rand()/RAND_MAX)*8-4;
        (arr+i)->vec[2]=((double)rand()/RAND_MAX)*8-4;
        (arr+i)->vec[3]=((double)rand()/RAND_MAX)*8-4;
        removeElem(arr+i, 2);
    }
    qsort(arr,sizeof(arr)/sizeof(vecgen_t),sizeof(vecgen_t),compLargo);
    for(int i=0;i<sizeof(arr)/sizeof(vecgen_t);i++ ){
        free((arr+i)->vec);
    }
    return 0;
}
//Funcion 
int removeElem(vecgen_t* p, int ind){
    double *p_aux;
    p->len--;
    if(ind > p->len || ind<0 || !p || p->len<0){
        p->len ++;
        return 0;
    }
    for(int i=ind; i<(p->len) ; i++){
        p->vec[i]= p->vec[i+1];
    }
    if(!(p_aux=realloc(p->vec,sizeof(double)*(p->len))) && (p->len)){
        p->len ++;
        return 0;
    }
    p->vec=p_aux;
    return 1;
}
int compLargo(const void* p1, const void* p2){
    vecgen_t* a=(vecgen_t*) p1;
    vecgen_t* b=(vecgen_t*) p2;
    return a->len - b->len;
}
