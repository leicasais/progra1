#include <stdio.h>
int main(void)
{
    char a[] = "hola";
    void *p;
    p = &a;
    printf("a: %s\n",(char*)p);
    return 0;
}