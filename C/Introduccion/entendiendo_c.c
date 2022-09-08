#include <stdio.h>
#include <stdlib.h>

/*
Tipos nativos:
    char (1 byte)         -128/127
    unsigned char (1 byte)         0/255
    short (2 bytes)       -32768/32767 #lo que yo represento puede tener signo
    int (4 bytes)         -2³¹/ 2³¹-1
    unsigned int (4 bytes)         0 / 4,294,967,295
    unsigned long (8 bytes)         0 / 18,446,744,073,709,551,615
    long int (8 bytes)     -2⁶³/ 2⁶³-1
    float (4 bytes)      +/- 1,8*10⁻⁺³⁸
    double (8 bytes)       +/- 1,8*10⁻⁺³⁰⁸

-----2----
a) 4 bytes 
b) 

-----4----
6 es un int
'6' estamos hablando del caracter 6
"6" es un string

*/
//-----5----
#define M_PI 3.14159265358979
#define STR_HOLA_MUNDO "Hola mundo"
#define NOTA_MAX 10
#define NOTA_MIN_APROBADO 4
#define SEGxHORA 3600

/*
//-----7----

int main(void){
    // float M_PI=3.14159; // no se puede re definir
    printf("%f\n",M_PI);
    return EXIT_SUCCESS;
}
//-----8----
int main(void){
    int nota=4; 
    if(nota==NOTA_MAX){
        printf("si\n");
    }
    else{
        printf("no\n");
    }
    return EXIT_SUCCESS;
} 
//-----9----
int main(void){
    int r=24;
    float f=2.3;

    printf("entero: %i\nreal: %f\n",r,f);
    return EXIT_SUCCESS;
} 

//-----10----

printf ("El producto de %d y %d es %d"\n, x, y, z);

suma=a + b;

/* Programa para obtener el máximo */ /*

if (numero >= maximo);

printf ("El resto de dividir %d por %d es %d\n", numerador, denominador, numerador % denominador);

if (x == y) printf ("%d es igual a %d\n", x, y);

printf ("La suma da %d\n", x + y);

//-----11----
int main(){
    char a='A';
    printf("%c\n",a);
    return EXIT_SUCCESS;
}

//-----12----
int main(void){
    int i=4;
    char a='4';

    int b='3';
    char c='8';

    char d='a';
    char e='b';

    printf("%c\n",b-c);
    printf("%c\n",d-e);
    if(a==i){
        printf("si\n");
    }
    else{
        printf("no\n");
    }
    return EXIT_SUCCESS;
}

//-----13----
#include <limits.h>

int main(void){
    printf("INT_MIN: %i\n",INT_MIN);
    printf("INT_MAX: %i\n",INT_MAX);
    printf("RAND_MAX: %i\n",RAND_MAX);
    printf("UINT_MAX: %i\n",UINT_MAX);
    return EXIT_SUCCESS;
}

//-----14----
int main(){
    char nombre[20];
    char apellido[20];
    char num[20];
    int i,j;
    
    printf("INGRESE NOMBRE (max 20 digitos):\n");
    fgets(nombre,20,stdin);
    printf("\n");

    printf("INGRESE APELLIDO (max 20 digitos):\n");
    fgets(apellido,20,stdin);
    printf("\n");

    printf("INGRESE numero(max 20 digitos):\n");
    fgets(num,20,stdin);
    printf("\n");
    
    printf("nombre: ");
    j=strlen(nombre);
    for(i=0;i<=j;i++){
        printf("%c",nombre[i]);
    }
    printf("apellido: ");
    j=strlen(apellido);
    for(i=0;i<=j;i++){
        printf("%c",apellido[i]);
    }
    printf("numero: ");
    j=strlen(num);
    for(i=0;i<=j;i++){
        printf("%c",num[i]);
    }
    return EXIT_SUCCESS;
}
//-----15----
int main(){
    char a[10]="3.1415";
    printf("%.2f\n",M_PI);
    printf("%.3f\n",M_PI);
    printf("%f\n",M_PI);
    printf("%s\n",a);
    return EXIT_SUCCESS;
}

//-----16----
#include <stdbool.h>
//true=1 || false=0

*/


