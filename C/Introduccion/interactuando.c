#include <stdio.h>
#include <stdlib.h>
#include <math.h>


void inv_raiz(float a){
    printf("De %.2f: su inversa es %.2f y su raiz %.2f\n",a,-a,sqrt(a));
}

void dia(int i){
    switch((i-1)%7){
        case 1: 
            printf("Lunes\n");    
            break;
        case 2: 
            printf("Martes\n");    
            break;
        case 3: 
            printf("Miercoles\n");    
            break;
        case 4: 
            printf("Jueves\n");    
            break;
        case 5: 
            printf("Viernes\n");    
            break;
        case 6: 
            printf("Sabado\n");    
            break;
        default:
            printf("Domingo\n");    
            break;
    }
    
}

void hora(int i){
    int h,m,s;
    h=i/3600;
    i=i%3600;
    m=i/60;
    s=i%60;
    printf("Hora: %i - Min: %i - Seg: %i\n",h,m,s);
}

int main(void){
    //inv_raiz(4.00);
    //dia(294);
    //hora(3650);

    return EXIT_SUCCESS;
}