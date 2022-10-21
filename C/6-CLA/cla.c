#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <stdbool.h>


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
} argu_t;


static const char *valid_arg[] = {
    [PROD] = "*",
    [DIV] = "/",
    [SUM] = "+",
    [RES] = "-",
};


void doce(int argc,char *argv[]){
    int j=0,arg;
    for(int i=1;i<argc;i++){
        for(arg=0;sizeof(valid_arg)/sizeof(valid_arg[0]);arg++){
            if(!strcmp(argv[i],valid_arg[arg])){
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
 
typedef enum {
    COM,
    FIN,
    CANT,
    HELP,
} arg_t;


static const char *valid_args[] = {
    [COM] = "-a",
    [FIN] = "-b",
    [CANT] = "-n",
    [HELP] = "-h",
};

void trece(int argc,char *argv[]){
    int i,arg;
    char *ptr=NULL;
    double com,fin,cant;
    bool _com,_fin,_cant,_help;
    _com=_fin=_cant=_help=false;

    if(argc==2 || argc==7){

        for(i=1;i<argc;i++){
            for(arg=0;arg<sizeof(valid_args)/sizeof(valid_args[0]);arg++){
                if(!strcmp(argv[i],valid_args[arg])){
                    break;
                }
            }
            switch (arg){
                case COM:
                    i++;
                    com=strtod(argv[i],&ptr);
                    if ('\0' != *ptr) {
                        _com=false;
                    }
                    else _com=true;
                    break;
                case FIN:
                    i++;
                    fin=strtod(argv[i],&ptr);
                    if ('\0' != *ptr) {
                        _fin=false;
                    }
                    else _fin=true;
                    break;
                case CANT:
                    i++;
                    cant=strtod(argv[i],&ptr);
                    if ('\0' != *ptr) {
                        _cant=false;
                    }
                    else _cant=true;
                    break;

                case HELP:
                    i++;
                    _help=true;
                    break;
            
                default:
                    break;
            }
        }
        if(_com==_fin==_cant==true && _help==false){
            srand48(time(NULL));
            float numero;
            for(int m=0;m<cant;m++){
                numero=drand48()*(fin-com)+com;
                printf("%f\n",numero);
            }
        }

        else if(_help==true && _com==_fin==_cant==false){
            printf("NOMBRE\n    %s, sampler - genera lotes de números pseudo-aleatorios\n\nSINOPSIS\n   %s [-a A] [-b B] [-n N] [-h]\n\nDESCRIPCIÓN\n   Generar un lote de N números pseudo-aleatorios en el intervalo\n    [A,B). La distribución muestreada es U[A,B).\n\nOPCIONES\n  h\n     muestra esta ayuda.\n   a A\n       comienzo del intervalo. Valor por omisión: 0.0.\n   b B\n       fin del intervalo. Valor por omisión: 1.0.\n    n N\n       cantidad de muestras a tomar. Valor por omisión: 100.\n\nAUTORES\n  Antonio Tepsich\nLICENCIA\n GNU General Public License v3.0",argv[0],argv[0]);
        }

        else{
            puts("ERROR");
        }
    }

    else{
        puts("ERROR");
    }
}


typedef enum {
    ALFA,
    AMP,
    FREC,
    START,
    END,
    POINTS,
    HELP2,
} argumentos_t;


static const char *valid_argumentos[] = {
    [ALFA] = "-alfa",
    [AMP] = "-amp",
    [FREC] = "-frec",
    [START] = "-start",
    [END] = "-end",
    [POINTS] = "-points",
    [HELP2] = "-H",
};

void quince(int argc, char *argv[]){
    int i,arg;
    char *ptra=NULL;
    double alfa,amp,frec,start,end,points;
    bool _alfa,_amp,_frec,_start,_end,_points,_help;
    _alfa=_amp=_frec=_start=_end=_points=false;

    if(argc==2 || argc==13){

        for(i=1;i<argc;i++){
            for(arg=0;arg<sizeof(valid_argumentos)/sizeof(valid_argumentos[0]);arg++){
                if(!strcmp(argv[i],valid_argumentos[arg])){
                    break;
                }
            }
            switch (arg){
                case ALFA:
                    i++;
                    alfa=strtod(argv[i],&ptra);
                    if ('\0' != *ptra) {
                        _alfa=false;
                    }
                    else _alfa=true;
                    break;
                case AMP:
                    i++;
                    amp=strtod(argv[i],&ptra);
                    if ('\0' != *ptra) {
                        _amp=false;
                    }
                    else _amp=true;
                    break;
                case FREC:
                    i++;
                    frec=strtod(argv[i],&ptra);
                    if ('\0' != *ptra) {
                        _frec=false;
                    }
                    else _frec=true;
                    break;
                case START:
                    i++;
                    start=strtod(argv[i],&ptra);
                    if ('\0' != *ptra) {
                        _start=false;
                    }
                    else _start=true;
                    break;
                case END:
                    i++;
                    end=strtod(argv[i],&ptra);
                    if ('\0' != *ptra) {
                        _end=false;
                    }
                    else _end=true;
                    break;
                case POINTS:
                    i++;
                    points=strtod(argv[i],&ptra);
                    if ('\0' != *ptra) {
                        _points=false;
                    }
                    else _points=true;
                    break;

                case HELP2:
                    i++;
                    _help=true;
                    break;
            
                default:
                    break;
            }
        }
        if(_alfa==_amp==_frec==_start==_end==_points==true && _help==false){
            srand48(time(NULL));
            float numero,calc;
            for(int m=0;m<points;m++){
                numero=drand48()*(end-start)+start;
                calc=exp(-alfa*numero)*amp*cos(2*M_PI*frec*numero);
                printf("%f      %f\n",numero,calc);
            }
        }

        else if(_help==true && _alfa==_amp==_frec==_start==_end==_points==false){
            printf("NOMBRE\n    %s, sampler - genera lotes de números pseudo-aleatorios\n\nSINOPSIS\n   %s [-a A] [-b B] [-n N] [-h]\n\nDESCRIPCIÓN\n   Generar un lote de N números pseudo-aleatorios en el intervalo\n    [A,B). La distribución muestreada es U[A,B).\n\nOPCIONES\n  h\n     muestra esta ayuda.\n   a A\n       comienzo del intervalo. Valor por omisión: 0.0.\n   b B\n       fin del intervalo. Valor por omisión: 1.0.\n    n N\n       cantidad de muestras a tomar. Valor por omisión: 100.\n\nAUTORES\n  Antonio Tepsich\nLICENCIA\n GNU General Public License v3.0",argv[0],argv[0]);
        }

        else{
            puts("ERROR");
        }
    }

    else{
        puts("ERROR");
    }
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
    // doce(argc,argv);

    // ----------Argumentos no-posicionales-----------

    // trece(argc,argv);   
    // catorce(argc,argv);   //no lo dimos
    // quince(argc,argv);    //revisar con -h  

    return EXIT_SUCCESS;
}