
/*Verificación de Palíndromos
Escribir una función recursiva que verifique si una cadena es un palíndromo (se lee
igual al derecho y al revés). La función debe ignorar espacios y signos de
puntuación. La función debe ser recursiva, es decir, debe estar estructurada con
caso base y caso recursivo. Realizar un programa que permita que el usuario
ingrese una cadena, y use la función escrita anteriormente para verificar si es un
palíndromo. El programa debe mostrar el resultado de la evaluación en pantalla.
Realizar el programa dentro de un proyecto de Eclipse.
Algunos ejemplos de palíndromos válidos:
• "Anana"
• "Anita lava la tina"
• "La ruta natural"
• "A man, a plan, a canal, Panama"
*/
#include <stdio.h>
char mayus(char c);
int palindromo(char* p1, char*p2);
int main(void)
{
    char* l="A man, a plan, a canal, Panama";
    printf("%d",palindromo(l,l+29));
    return 0;
}


int palindromo(char* p1, char*p2){
    
    while(!((*p1>='A' && *p1<='Z') || (*p1>='0' && *p1<='9') || (*p1>='a' && *p1<='z')) && *p1)
        p1++;
    while(!((*p2>='A' && *p2<='Z') || (*p2>='0' && *p2<='9') || (*p2>='a' && *p2<='z')) && (p1<=p2))
        p2--;
    if(p1>=p2)
        return 1;
    if(mayus(*p1)!=mayus(*p2))
        return 0;
    return palindromo(p1+1,p2-1);
}
char mayus(char c){
    if(c>='a' && c<='z'){
        c+=(-'a'+'A');
    }
    return c;
}