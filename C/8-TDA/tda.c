#include <stdio.h>
#include "tda.h"

void uno(){
    punto_t* a=punto_crear(2,4);
    imprimir(a);
}

int main(){
    uno();

    return 0;
}