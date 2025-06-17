#define NMAX 10
typedef struct{
    char nom[20];
    int  fecha_inicio[3];
    int  fecha_fin[3];
}club_t;

typedef struct{
    char nom[20];
    char ape[20];
    club_t club_info[NMAX];
    
}futbolista_t;

int futjugaronjuntxs(futbolista_t* a, futbolista_t*b){
    int estado=1;
    for(int i=0;(a->club_info[i].nom[0]);i++){
        for(int j=0; (b->club_info[j].nom[0]) && estado;j++){
            for(int k=0; estado==0; k++){
                if(!((b->club_info[j].nom[k])==(a->club_info[i].nom[k]))){
                    estado=0;
                }
            }
            if(estado){
                if((b->club_info[j].fecha_inicio[2] > a->club_info[j].fecha_fin[2])|| (a->club_info[j].fecha_inicio[2] > b->club_info[j].fecha_fin[2])){
                    estado=0;
                }
                else{
                    if((b->club_info[j].fecha_inicio[1] > a->club_info[j].fecha_fin[1])|| (a->club_info[j].fecha_inicio[1] > b->club_info[j].fecha_fin[1]))
                        estado=0;
                    else{
                        if((b->club_info[j].fecha_inicio[0] > a->club_info[j].fecha_fin[0])|| (a->club_info[j].fecha_inicio[0] > b->club_info[j].fecha_fin[0])){
                            estado=0;
                        }
                        else{
                            j=NMAX;
                            i=NMAX;
                        }
                    }
                }
            }
            
        }
    }
    return estado;
}

