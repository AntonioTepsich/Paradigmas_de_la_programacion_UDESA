#include <stdio.h>
#include <string.h>
#include <stdlib.h>


typedef enum {
    ST_OK,
    ST_ERR, 
    ST_ERR_NULL_PTR, 
    ST_ERR_ENOMEM
} status_t;

//----------------1-----------------
typedef struct materia{
    char *nombre;
    char *codigo;
    float *notas;
    int cantidad;
    float notaFinal;
}materia_t;

typedef struct estudiante {
    const char *nombre;
    int carrera;
    materia_t *materias;
    int cantidadMaterias;
}estudiante_t;

//----------------2-----------------

status_t crearEstudiante(struct estudiante **estudiante,char*nombre_,int carrera_){
    struct estudiante *aux;

    if(estudiante==NULL || nombre_==NULL){
        return ST_ERR_NULL_PTR;
    }
    aux=calloc(1,sizeof(struct estudiante));
    if(aux==NULL){
        return ST_ERR_ENOMEM;
    }
    aux->nombre=strdup(nombre_);
    if(aux->nombre==NULL){
        free(aux);
        return ST_ERR_ENOMEM;
    }
    aux->carrera=carrera_;
    aux->materias=NULL;
    aux->cantidadMaterias=0;

    *estudiante=aux;
    return ST_OK;
}

//----------------3-----------------

status_t agregarMateria(struct estudiante *estudiante,const char* nombre_,const char* codigo_){
    struct materia* aux;
    if(estudiante==NULL || nombre_==NULL ||codigo_==NULL){
        return ST_ERR_NULL_PTR;
    }

    aux=(struct materia*)realloc(estudiante->materias,(estudiante->cantidadMaterias + 1) * sizeof(struct materia));
    if(aux==NULL){
        free(aux);
        return ST_ERR_ENOMEM;
    }

    estudiante->materias=aux;
    estudiante->materias->nombre=strdup(nombre_);
    estudiante->materias->codigo=strdup(codigo_);
    estudiante->materias->notas=NULL;
    estudiante->materias->notaFinal=0;
    estudiante->materias->cantidad=0;
    estudiante->cantidadMaterias++;

    return ST_OK;
}

//----------------4-----------------

status_t promedio(double *prom,const struct estudiante *estudiante){
    if(prom==NULL||estudiante==NULL||estudiante->materias==NULL){
        return ST_ERR_NULL_PTR;
    }
    *prom=estudiante->materias[0].notaFinal;
    size_t i=0;
    for(i; i<estudiante->cantidadMaterias;i++){
        *prom+=estudiante->materias[i].notaFinal;
    }
    *prom/=estudiante->cantidadMaterias;
    return ST_OK;
}

//----------------5-----------------
status_t agregarMateria2(struct estudiante *estudiante,const char* nombre_,const char* codigo_){
    struct materia** aux;
    struct materia* nuevaMat;
    if(estudiante==NULL || nombre_==NULL ||codigo_==NULL){
        return ST_ERR_NULL_PTR;
    }

    nuevaMat=(struct materia*)calloc(1,sizeof(struct materia));

    if(nuevaMat==NULL){
        free(nuevaMat);
        return ST_ERR_ENOMEM;
    }

    aux=(struct materia **) realloc(estudiante->materias,(estudiante->cantidadMaterias+1)*sizeof(struct materia *));
    if(aux==NULL){
        free(nuevaMat);
        free(aux);
        return ST_ERR_ENOMEM;
    }

    estudiante->materias=aux;
    nuevaMat->nombre=strdup(nombre_);
    nuevaMat->codigo=strdup(codigo_);
    nuevaMat->notas=NULL;
    nuevaMat->notaFinal=0;
    nuevaMat->cantidad=0; 

    estudiante->materias=nuevaMat;
    estudiante->cantidadMaterias++;
    return ST_OK;
}

int main(int argc, char const *argv[])
{
    uno();
    return 0;
}
