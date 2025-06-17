int suma_digitos(int n1)
{
return ((n1 % 10) + digitos(n1 / 10)); //caso recursivo
}
/*
a. ¿Cuál es el objetivo de la función? Sumar todos los digitos del numero
b. ¿Por qué no funciona? Por que no contempla el caso base 0 y quedaria en un loop infinito, aria 0/10=0 -> +0 y repite. Ademas se esta llamando a la funcion equivocada
c. Crear un repositorio de GitHub y subir un main utilizando la
función tal cual está escrita. Luego, corregir la función,
realizar un commit y pushearlo al repositorio.*/
int suma_digitos2(int n1)
{
    if(n1==0){
        return 0;
    }
    return ((n1 % 10) + suma_digitos2(n1 / 10)); //caso recursivo
}