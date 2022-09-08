#include <stdio.h>
#include <stdlib.h>
#include <math.h>


void ceros(){
    int a[15]={0};
    for (size_t i = 0; i < 15; ++i) {
        printf("%i\n",a[i]); 
    }
}
void tres(){
    double a[7]={0};
    for (size_t i = 0; i < 7; ++i) {
        a[i]=3.0;
        printf("%.1f\n",a[i]); 
    }
}
#define SIZE 7
void tamano(){
    float a[SIZE]={0};
    printf("%li\n",sizeof(a)/sizeof(float)); 
    
}
void cuatroi(){
    int a[4]={3,2,0,9};
    for (size_t i = 0; i < 4; ++i) {
        printf("%i\n",a[i]); 
    }
}
void cuatroc(){
    char a[4]={'h','o','l','a'};
    for (size_t i = 0; i < 4; ++i) {
        printf("%c\n",a[i]); 
    }
}
void cuatrog(){
    int a[4]={104, 111, 108, 97};
    for (size_t i = 0; i < 4; ++i) {
        printf("%i\n",a[i]); 
    }
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

void ingreso(){
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

void abs_rel(){
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
void histograma(){
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

int main(void){
//-----------1----------
    //ceros(15); //a
    //tres(); //b
    //tamano(); //c
    //cuatroi(); //d
    //cuatroc(); //e
    //cuatrog(); //f

//-----------2----------
    //ceros_10(); //a
    //sumav();  //b

//-----------3----------
    //ingreso();

//-----------4----------
    //abs_rel();

//-----------5----------
    //histograma();

//-----------6----------
    /*
    a) int a[10] tiene 10 elementos de int y ocupa 40 bytes. int a[2] tiene 2 elementos de int y ocupa 8 bytes. 
    b) float a[10] tiene 10 elementos de float y ocupa 40 bytes. float a[2] tiene 2 elementos de float y ocupa 8 bytes. 
    c) char a[10] tiene 10 elementos de char y ocupa 10 bytes. char a[2] tiene 2 elementos de char y ocupa 2 bytes. 
    
   float a[10];
    printf("%li",sizeof(a));
    */
    return EXIT_SUCCESS;
}
