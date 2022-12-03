#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <math.h>

void uno(){
    /*
    a)  FALSO - solo podes crear un arreglo para cada tipo de valor
    b)  FALSO - siempre tiene que ir un entero de subindice i
    c)  FALSO - si hay menos inicializadores en la lista, el arreglo se termina de completar con ceros (0)
    d)  VERDADERO
    e)  FALSO - de manera estatica es imposible modificarlo
    */
}

void PrintInt(int a[],int n){
    for (size_t i = 0; i < n; ++i) {
        printf("%i\n",a[i]); 
    }
}
void PrintDouble(double a[],int n){
    for (size_t i = 0; i < n; ++i) {
        printf("%i\n",a[i]); 
    }
}
void PrintFloat(float a[],int n){
    for (size_t i = 0; i < n; ++i) {
        printf("%i\n",a[i]); 
    }
}
void PrintChar(char a[],int n){
    for (size_t i = 0; i < n; ++i) {
        printf("%i\n",a[i]); 
    }
}

void sumar(int a[],int n){
    int sum=0;
    for(size_t i=0;i<n;i++){
        sum+=a[i];
    }
    printf("%i",sum);
}
#define SIZE 7

void dos(){
    int a[15]={0};
    double b[7];
    for(size_t i=0;i<7;i++){
        b[i]=3.0;
    }
    float c[SIZE]={0};
    int d[4]={3,2,0,9};
    char e[4]={'h','o','l','a'};
    int f[4]={104, 111, 108, 97};

    sumar(d,4);
}

void ceros_10(){
    int a[10]={0};
    for (size_t i = 0; i < 10; ++i) {
        printf("%i\n",a[i]); 
    }
}

void sumav(){
    int a[15]={1},x=0;
    for (size_t i = 0; i < 15; ++i) {
        a[i]=i+1;
        x+=i;
    }
    printf("%i\n",x); 
}
 
void tres(){
    ceros_10(); //a
    //sumav();  //b
}
 
void cuatro(){
    int a[5];
    float s=0,v=0;
    printf("ingrese numeros:\n");
    for(size_t i=0;i<5;i++){
        scanf("%i",&a[i]);
    }
    for (size_t i = 0; i < 5; ++i) {
        s+=a[i];
    }
    s=s/5;
    for (size_t i = 0; i < 5; ++i) {
        v+=pow(a[i]-s,2);
    }
    v=v/5;
    printf("media: %.2f - varianza^2: %.2f\n",s,v); 
}
 
void cinco(){
    float x;
    printf("Ingrese la cantidad de números a generar (10 - 10000): ");
    scanf("%f",&x);
    printf("\n");
    int a[10]={1008,1023,867,1061,966,1057,980,1010,951,977};
    float b[10];
    for(size_t i=0;i<10;i++){
        b[i]=a[i]/x;
        printf("%lis: %i (%.4f)\n",i,a[i],b[i]);
    }
}
 
void seis(){
    printf("Elemento    Valor   Histograma\n");
    int a[10]={1008,1023,867,1061,966,1057,980,1010,951,977},num;
    char b;
    for(size_t i=0;i<10;i++){
        num=a[i]/100;
        b='*';
        printf("%li    %i    ",i,a[i]);
        for(size_t j=0;j<num;j++){
            printf("%c",b);
        }
        printf("\n");
    }
}

void site(){
    /*
    a) int a[10] tiene 10 elementos de int y ocupa 40 bytes. int a[2] tiene 2 elementos de int y ocupa 8 bytes. 
    b) float a[10] tiene 10 elementos de float y ocupa 40 bytes. float a[2] tiene 2 elementos de float y ocupa 8 bytes. 
    c) char a[10] tiene 10 elementos de char y ocupa 10 bytes. char a[2] tiene 2 elementos de char y ocupa 2 bytes. 
    
   float a[10];
    printf("%li",sizeof(a));
    */
}

void ochosub(int c[], int n,int x){
    for (size_t i = 0; i < n; ++i) {
        c[i]=x;
        printf("%i\n",c[i]); 
    }
}

void ocho(){
    int c[6]={0, 1, 2, 3, 10, 11};
    // ----------a------------
    ochosub(c,sizeof(c)/4,0); 

    // ----------b------------
    ochosub(c,sizeof(c)/4,1); 

}

void dieciseissub(int c[][3], int n,int x){
    for (size_t i = 0; i < n; ++i) {
        for(size_t j=0;j<(sizeof(c[0])/sizeof(int));j++){
            c[i][j]=x;
            printf("%i",c[i][j]); 
        }
        printf("\n"); 
    }
}

void dieciseis(){
    int c[3][3]={0, 1, 2, 3, 10, 11,12,4,8};
    // ----------a------------
    dieciseissub(c,3,0); 

    // ----------b------------
    dieciseissub(c,3,1); 

}

void dieciochosub(int c[][3],int n){
    int tr=0;
    for(size_t i=0;i<n;i++){
        for(size_t j=0;j<(sizeof(c[0])/sizeof(int));j++){
            if(i==j) {
                tr+=c[i][j];
                //printf("%i\n",c[i][j]);
                break;
            }
        }
    }
    printf("traza = %i\n",tr);
}

void dieciocho(){
    int c[3][3]={0, 1, 2, 3, 10, 11,12,4,8};

    // ----------a------------
    dieciochosub(c,3);

}

 
void veintesub(int c[][20], int w){
    for(size_t i=0;i<7;i++){
        for(size_t j=0;j<20;j++){
            printf("%i ",c[i][j]);
        }
        printf("\n");
    }
}

void veinte(){
    int c[7][20]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,0,0,1,1,1,0,0,1,1,1,0,0,1,1,1,0,0,1,0,1,0,0,1,0,1,0,0,0,1,0,0,0,1,0,1,0,0,1,0,1,0,0,1,0,1,0,0,0,1,0,0,0,1,0,1,0,0,1,1,1,0,0,1,1,1,0,0,0,1,0,0,0,1,0,1,0,0,1,0,0,0,0,1,0,1,0,0,0,1,0,0,0,1,0,1,0,0,1,0,0,0,0,1,0,1,0,0,0,1,0,0,0,1,1,1,0};
    int x=20;
    veintesub(c,x);
}


void veinticinco(){

    const int ancho=10,alto=10,seed=2;

    int c[ancho][alto];
    srand(time(NULL));
    int i,n,s=0,f;
    int co,cont,cont2;
    
    printf("Inicio\n");
    for(size_t fila=0;fila<ancho; fila++){
        for(size_t col=0; col<alto; col++ ){
            for(size_t i=0;i<(10);i++){
                n=rand()%2;     
            }
            c[fila][col]=n;
            printf("%d",c[fila][col]);
        }
        printf("\n");
    }


    while(s<seed){  //cantidad de veces que se repite
        printf("Iteracion numero %i\n",(s+1));

        for(size_t fila=0;fila<ancho;fila++){  //genera ataques
            for(size_t col=0;col<alto;col++){
                cont=0;
                cont2=0;
                f=fila;
                co=col;
                if(c[f][co]==1){
                    if((f-1)>=0){
                        if(c[f-1][co]==1){
                            cont++;
                        }
                    } 
                    if((f+1)<ancho){
                        if(c[f+1][co]==1){
                            cont++;
                        }
                    } 
                    if(co-1>=0){
                        if(c[f][co-1]==1){
                            cont++;
                        }
                    } 
                    if(co+1<alto){
                        if(c[f][co+1]==1){
                            cont++;
                        }
                    }
                    if(f-1>=0 && co+1<alto){
                        if(c[f-1][co+1]==1){
                            cont++;
                        }
                    }
                    if(f-1>=0 && co-1>=0){
                        if(c[f-1][co-1]==1){
                            cont++;
                        }
                    }
                    if(f+1<ancho && co-1>=0){
                        if(c[f+1][co-1]==1){
                            cont++;
                        }
                    }
                    if(f+1<ancho && co+1<alto){
                        if(c[f+1][co+1]==1){
                            cont++;
                        }
                    }
                }
                else{
                    if((f-1)>=0){
                        if(c[f-1][co]==1){
                            cont2++;
                        }
                        
                    } 
                    if((f+1)<ancho){
                        if(c[f+1][co]==1){
                            cont2++;
                        }
                    } 
                    if(co-1>=0){
                        if(c[f][co-1]==1){
                            cont2++;
                        }
                    } 
                    if(co+1<alto){
                        if(c[f][co+1]==1){
                            cont2++;
                        }
                    }
                    if(f-1>=0 && co+1<alto){
                        if(c[f-1][co+1]==1){
                            cont2++;
                        }
                    }
                    if(f-1>=0 && co-1>=0){
                        if(c[f-1][co-1]==1){
                            cont2++;
                        }
                    }
                    if(f+1<ancho && co-1>=0){
                        if(c[f+1][co-1]==1){
                            cont2++;
                        }
                    }
                    if(f+1<ancho && co+1<alto){
                        if(c[f+1][co+1]==1){
                            cont2++;
                        }
                    }
                }

                if(cont<2){
                    c[f][co]=0;
                }

                else if(cont==2 || cont==3){
                    c[f][co]=1;
                }
                else if(cont>3){
                    c[f][co]=0;
                }
                if(cont2==3) c[f][co]=1;
            }
        }
        for(size_t fila=0;fila<ancho; fila++){
            for(size_t col=0; col<alto; col++ ){
                printf("%d",c[fila][col]);
            }
            printf("\n");
        }
        printf("\n");
        s++;
    }
}

void print(int a[][3],int f){
    for(size_t i=0;i<f;i++){
        for(size_t j=0;j<3;j++){
            a[i][j]=j;
        }
    }
    for(size_t i=0;i<f;i++){
        for(size_t j=0;j<3;j++){
            printf("%i, ",a[i][j]);
        }
        printf("\n");
    }
}

void extra(){
    int a[2][3];
    print(a,2);
}

int main(void){

    extra();

    // ----------Arreglos-----------

    // uno();

    // ----------Arreglos unidimensionales-----------

    // dos();
    // tres();     
    // cuatro();     
    // cinco();     
    // seis();     
    // site();     

    // ----------Funciones con arreglos unidimensionales-----------

    // ocho();
    // nueve();     //falta
    // diez();     //falta
    // once();     //falta
    // doce();     //falta
    // trece();     //falta
    // catorce();     //falta
    // quince();     //falta

    // ----------Funciones con arreglos multidimensionales-----------

    // dieciseis();
    // diecisiete(); //falta
    // dieciocho();
    // diecinueve();  //falta

    // ----------Gráficos Net PBM-----------

    // veinte();
    // veintiuno();    //falta
    // veintidos();    //falta
    // veintitres();    //falta
    // veinticuatro();    //falta

    // ----------Conway’s game of LIFE-----------

    // veinticinco();   //juego con las 4 reglas principales

    return EXIT_SUCCESS;
}