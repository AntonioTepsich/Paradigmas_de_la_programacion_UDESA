/*
-------1------
a)  FALSO - solo podes crear un arreglo para cada tipo de valor
b)  FALSO - siempre tiene que ir un entero de subindice i
c)  FALSO - si hay menos inicializadores en la lista, el arreglo se termina de completar con ceros (0)
d)  VERDADERO
e)  FALSO - de manera estatica es imposible modificarlo
*/
#include <stdio.h>
#include <stdlib.h>



int main(void){
    int a[5]={1,2,3,4,5};
    for (size_t i = 0; i < 5; ++i) {
        printf("%i\n",a[i]); 
    }
    return EXIT_SUCCESS;
}