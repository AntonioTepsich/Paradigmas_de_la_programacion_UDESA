#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b){
    int aux=*a;
    *a=*b;
    *b=aux;
}

void a_hms(int segundos,int *h,int *m, int *s){
    *h=segundos/3600;
    *m=(segundos%3600)/60;
    *s=(segundos%3600)%60;
}

int main(){
    int a=1,b=2,h,m,s,x=3666;
    swap(&a,&b);
    printf("a:%i b:%i\n",a,b);
    printf("\n");

    a_hms(x,&h,&m,&s);
    printf("%i %i %i son %i\n",h,m,s,x);
    printf("\n");

    
    return 0;
}