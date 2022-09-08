#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int es_primo(int p){
    int i, contador=0;
    for(i=1;i<p;i++){
        if(p%i==0) contador++;
    }
    if(contador>1) return 0; //false
    else return 1;  //true
}

void mayor_igual(int x,int y){
    if(x>y) printf("%i es mayor que %i\n",x,y);
    else if(x<y) printf("%i es mayor que %i\n",y,x);
    else printf("%i y %i son iguales\n",y,x);
}

int absoluto(int i){
    if(i<0){
        i= -i;
    }
    return i;
}

void identidad(){
    int i,j;
    char a[3][3]={1,2,3,4,5,6,7,8,9};
    for(i=0;i<sizeof(a)/sizeof(a[0]);i++){
        for(j=0;j<sizeof(a[i]);j++){
            if(i==j){
                a[i][j]=1;
            } 
            else{
                a[i][j]=0;
            }
        }
    }
    for(i=0;i<sizeof(a)/sizeof(a[0]);i++){
        for(j=0;j<sizeof(a[i]);j++){
            printf("%i",a[i][j]);
        }
        printf("\n");
    }
}

void raiz_grado_2(float a,float b, float c,float h){
    float d=b*b-4.00*a*(c-h);
    float result1=(-b+sqrt(d))/(2*a);
    float result2=(-b-sqrt(d))/(2*a);

    printf("Las raices de %.2fx^2+%.2fx+%.2f=%.2f son: %.2f y %.2f\n",a,b,c,h,result1,result2);
}

void intereseccion(float a,float b, float c,float d){
    float x=(d-b)/(a-c);
    float y=a*x+b;

    printf("Las rectas %.2fx+%.2f y %.2fx+%.2f se intersectan en: X=%.2f - Y=%.2f\n",a,b,c,d,x,y);
}

void bisiesto(int x){
    if(x%4==0 && x%100!=0 && x%400!=0){
        printf("%i es bisiesto\n",x);
    }
    else{
        printf("%i no es bisiesto\n",x);
    }
}

void min_billetes(int x){
    int u,d,c;
    u=(x%100)/10;
    d=((x-u)%1000)/100;
    c=((x-u-d)%10000)/1000;

    printf("%i ARS = (%ix1000 ARS + %ix100 ARS + %ix10 ARS)\n",x,c,d,u);
}

void decision_multiple(char a){
    switch (a){
    case 'A':
        printf("Ada Lovelace\n");
        break;
    case 'a':
        printf("Alan Turing\n");
        break;
    case 'B':
        printf("Brian Kernighan\n");
        break;
    case 'b':
        printf("Bjarne Stroustrup\n");
        break;
    case 'D':
        printf("Dennis Ritchie\n");
        break;
    case 'G':
        printf("Hedy Lamarr\n");
        break;
    case 'H':
        printf("Ida Rhodes\n");
        break;
    case 'I':
        printf("Margaret Hamilton\n");
        break;
    case 'M':
        printf("Maddog Hall\n");
        break;
    
    default:
        printf("No lo conozco\n");
        break;
    }

}

int main(){
    int i;
    // i = es_primo(5); //1   //mayor que 1
    // mayor_igual(5,5);  //2
    // i=absoluto(4); //3
    // identidad(); //4
    // raiz_grado_2(1.00,4.00,1.00,2.00);//5
    // intereseccion(-2.00,1.00,3.00,6.00); //6
    // bisiesto(1905); //7a
    // min_billetes(2320); //8
    decision_multiple('M'); //10

    // printf("%i\n",i);
    return EXIT_SUCCESS;
}