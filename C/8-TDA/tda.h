#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct punto{
    double x;
    double y;
}punto_t;


punto_t *punto_crear(double x_, double y_){
    punto_t* puntos=(punto_t *)malloc(sizeof(punto_t));
    puntos->x=x_;
    puntos->y=y_;
    return puntos;
}

void punto_destruir(punto_t *s){
    free(s);
}

punto_t * punto_copiar(const punto_t *s2){
    punto_t* s1;
    s1=(punto_t *)malloc(sizeof(punto_t));
    strncpy(s1,s2);
    return s1;
}

double punto_get_x(const punto_t *s1){
    return s1->x;
}

void imprimir(punto_t* s){
    double xs=s->x;
    double ys=s->y;
    printf("x: %f\ny: %f\n",xs,ys);
}