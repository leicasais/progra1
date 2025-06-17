#include <stdlib.h>
int borrar (void);
int aceptar(void);
typedef struct {
    char tecla;
    int (*action) (void);
}menu_t;

int main(int argc, char const *argv[])
{
    menu_t menu_list[2]={{'*',borrar},{'#', aceptar}};
    //OR
    menu_t menu_list[2];
    menu_list->tecla='*';
    menu_list->action=borrar;
    menu_list[1].tecla='#';
    menu_list[1].action=aceptar;

    
    return 0;
}

