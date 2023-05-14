#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef enum{ST_OK,ST_ERR}status_t;

int gauss_sum(int n){
    int r=0;
    for(int i=0;i<n;i++){
        r+=i;
    }
    return r;
}
status_t gauss_sum2(int *r,int n){
    int x=gauss_sum(n);
    *r=x;
    return ST_OK;
}

double abs(double x){
    if (x<0){
        return -x;
    }
    else{
        return x;
    }
}

double mus(double *lista,size_t l){
    double sum=0;
    for(size_t i=0;i<l;i++){
        sum+=lista[i];
    }
    return sum;
}

double search(double *lista,size_t l,int n){
    double mu=mus(lista,l);
    size_t meni=NULL;
    double menu;
    for(size_t i=0;i<l-n;i++){
        double sum=0;
        for(size_t j=i;j<i+n;j++){
            sum+=abs(lista[j]-mu);
        }
        sum/=n;
        if(meni==NULL){
            meni=i;
            menu=sum;
        }
        else if(sum<menu){
            meni=i;
            menu=sum;
        }
    }
    return meni;
}

int cuatro(int argc,char* argv[]){
    int mayor=0;
    int sa=0;

    for(size_t i=0;i<argc;i++){
        if(mayor<strlen(argv[i])){
            mayor=strlen(argv[i]);
            sa=i;
        }
    }
    printf("%s",argv[sa]);
}

char *strdup(char *cad){
    char *s1;
    s1=(char *)malloc(strlen(cad)+1);
    return strcpy(s1,cad);
}


void identidad(double **matriz,size_t filas,size_t columnas){
    for(size_t i=0;i<columnas;i++){
        for(size_t j=0;j<filas;j++){
            if(i==j){
                matriz[i][j]=1;
            }
            else{
                matriz[i][j]=0;
            }
        }
    }
}

status_t identidadd(double **matriz,size_t filas,size_t columnas){
    if(matriz==NULL || filas!=columnas){
        return ST_ERR;
    }

    for(size_t i=0;i<columnas;i++){
        for(size_t j=0;j<filas;j++){
            if(i==j){
                matriz[i][j]=1;
            }
            else{
                matriz[i][j]=0;
            }
        }
    }
    return ST_OK;
}

int suma(double **matriz,size_t filas,size_t columnas){
    double mayor;
    size_t indice=NULL;
    if(matriz!=NULL && filas!=columnas){
        for(size_t i=0;i<filas;i++){
        double sum=0;
            for(size_t j=0;j<columnas;j++){
                sum+=matriz[i][j];
            }
            if(indice==NULL){
                mayor=sum;
                indice=i;
            }
            else if(mayor<sum){
                mayor=sum;
                indice=i;
            }
        }
    }
}

status_t traza(double *t,float **matriz,size_t filas, size_t columnas){
    if(matriz==NULL || filas!=columnas){
        return ST_ERR;
    }
    float traza=0;
    for(size_t i=0;i<columnas;i++){
        for(size_t j=0;j<filas;j++){
            if(i==j){
                traza+=matriz[i][j];
            }
        }
    }
    *t=traza;
    return ST_OK;
}

int main(int argc,char* argv[]){
    int menor=1;
    for(int i=2;i<argc;i++){
        if(argv[menor]<argv[i]){
            menor=i;
        }
    }
    puts(argv[menor]);
    return 0;
}

int *crearVector(int n){
    int *v;
    v=(int *)malloc(n*sizeof(int));
    if(v==NULL){
        free(v);
        return NULL;
    }
    for(size_t i=0;i<n;i++){
        v[i]=0;
    }
    return v;
}