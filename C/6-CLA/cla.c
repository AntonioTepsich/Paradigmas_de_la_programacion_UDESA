#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>


void uno(){
    /*
    En C, estos argumentos se pasan a la función main, como cualquier otro argumento a una función.
    El sistema operativo carga en argc la cantidad de argumentos recibidos, y en argv carga los argumentos 

    Si ingresamos en la terminal:
        $ gcc -std=c17 -Wall -pedantic -o mi_programa app.c -lm
    es como recibir:
        char *argv[] = {"gcc", "-std=c17", "-Wall", "-pedantic", "-o", "mi_programa", "app.c", "-lm", NULL};
        int argc = 8;

    Hay 2 tipos de argumentos, los posicionales y no posicionales
    */
}

void dos(int argc,char *argv[]){
// ----------a------------
    printf("argc: %i\n",argc);
// ----------b------------
    for(size_t i=0;i<argc;i++){
        printf("argv %li: %s\n",i,argv[i]);
    }
}
 
void tres(int argc,char *argv[]){
    for(size_t i=0;i<argc;i++){
        printf("argv %li: %s\n",i,argv[i]);
    }
}
 
void cuatro(int argc,char *argv[]){
    int x;
    for(size_t i=0;i<argc;i++){
        x=strlen(argv[i]);
        printf("argv [%li]: %i\n",i,x);
    }
}
 
void cinco(char *argv1,char *argv2){
    if  ( strlen ( argv1 ) != strlen ( argv2 ) ) {
        if  ( strlen ( argv1 ) < strlen ( argv2 ) ) {
            puts("argv[1] < argv[2]");
        }
        if  ( strlen ( argv1 ) > strlen ( argv2 ) ) {
            puts("argv[1] > argv[2]");
        }
    }
    int x=0;
    for(size_t i=0;i<strlen(argv1);i++){
        if  ( argv1[ i ] != argv2[ i ] ) {
            x=1;
            puts("Son todos distintos\n");
            break;
        }
    }
    if(x==0){
        puts("son iguales\n");
    }
}
 
void seis(int argc,char *argv[]){
    float x;
    x=pow(pow(atoi(argv[1]),2)+pow(atoi(argv[2]),2),0.5);
    printf("modulo entre %s y %s es %.2f\n",argv[1],argv[2],x);    
}

void siete(int argc,char *argv[]){

}
 
void ocho(int argc,char *argv[]){

}
 
void nueve(char *x_i,char *x_f,char *n){
    srand48(time(NULL));
    float xi,xf,numero;
    int hasta;
    xi=atoi(x_i);
    xf=atoi(x_f);
    hasta=atoi(n);
    for(int i=0;i<hasta;i++){
        numero=drand48()*(xf-xi)+xi;
        printf("%f\n",numero);
    }
}
 
void diez(int argc,char *argv[]){

}
 
void once(int argc,char *argv[]){

}

typedef enum {
    PROD,
    DIV,
    SUM,
    RES,
} arg_t;


static const char *valid_args[] = {
    [PROD] = "*",
    [DIV] = "/",
    [SUM] = "+",
    [RES] = "-",
};

void doce(int argc,char *argv[]){
    int j=0,arg;
    for(int i=1;i<argc;i++){
        for(arg=0;sizeof(valid_args)/sizeof(valid_args[0]);arg++){
            if(!strcmp(argv[i],valid_args[arg])){
                break;
            }
        }
        switch (arg){
            case PROD:
            case DIV:
            case SUM:
            case RES:
                j++;
                break;
            default:
                break;
        }
    }

    printf("%d\n",j);
}
 
 

int main(int argc, char *argv[]){

    // ----------Argumentos en línea de comandos-----------
    // uno();
    //dos(argc,argv);

    // ----------Argumentos posicionales-----------
    // tres(argc,argv);     
    // cuatro(argc,argv);     
    // cinco(argv[1],argv[2]);     
    // seis(argc,argv);  
    // siete(argc,argv);  //nose que te pide
    // ocho(argc,argv); //no lo dimos
    // nueve(argv[1],argv[2],argv[3]);
    // diez(argc,argv);   //no lo dimos
    // once(argc,argv);   //no lo dimos
    // char *argv[]={"./cla" , "-3", "2", "+", "*",NULL};
    // int argc=5;
    doce(argc,argv);

    return EXIT_SUCCESS;
}