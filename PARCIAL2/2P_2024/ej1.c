#include <stdio.h>
void printNum(unsigned int num);

int main(int argc, char const *argv[])
{
    printNum(1290);
    putchar('\n');
    return 0;
}

void printNum(unsigned int num){
    if(num<10){//Caso base num<10 -> se pude printear perfectamente usando putchar()
        putchar('0'+num);
    }
    else{
        printNum(num/10);//importante no returnear funcion si es void
        putchar('0'+num%10);
    }
}