
#include <stdio.h>
//---------------1------------------------
long gauss_sum1(int n){
    long r=0;

    for (int k=0;k<n;k++){
        r+=k;
    }
    return r;
}

status_t gauss_sum2(long *r,int n){
    if(NULL==r){
        return ST_ERR_NULL_PTR;
    }
    if(n<=0){
        return ST_INVALID_ARG;
    }
    *r=gauss_sum1(n);

    return ST_OK;
}


//---------------2------------------------
/*
[1,2,3,4,5],3         ESTO TE PASAN EN LA FUNCION
u0=(1+2+3)/3           CALCULAR MU
s0= (abs(1-2)+abs(2-2)+abs(3-2))/3   DA 2/3      
u1=(2+3+4)/3           
s1= (abs(2-3)+abs(3-3)+abs(4-3))/3   DA 2/3

me quedo con el primero
*/

double mean(double *v,size_t n){
    double suma=0;

    for (size_t i=0;i<n;i++){
        suma+=v[i];
    }
    return suma/n;
}

double std(double *v,size_t n){
    double s=0;
    double mu=mean(v,n);
    for(size_t i=0;i<n;i++){
        double aux=v[i]-mu;
        if(aux<0){
            aux=-aux;
        }
    }
    /*
    OTRA OPCION UTILIZANDO fabs()
    for(size_t i=0;i<n;i++){
        s+=fabs(v[i]-mu);
    }
    */
    return s/n;
}

ssize_t search(double *v,size_t l, int n){
    ssize_t index=0,i;
    double s_min;

    if(NULL==v){
        return -1;
    }

    if(n<=0 || l==0 || n>l){
        return -1;
    }
    s_min=std(v,1);
    index=0;
    for(size_t i=1;i<l-n;i++){
        double s=std(&v[i],n);
        if(s<s_min){
            index=i;
            s_min=s;
        }
    }
    return i;
}

//double x[]={1,2,3,4};
//ssize_t i= search(x,4,2);


//---------------3------------------------

#include <stdio.h>
#include <string.h>

int main(int argc,char *argv[]){
    int index=0;
    size_t max_len;

    for(size_t i=2;i<argc;i++){
        size_t len = strlen(argv[i]);
        if(len>max_len){
            index=i;
            max_len=len;
        }
    }
    puts(argv[index]);
    return 0;
}


//---------------4------------------------

#include <stdlib.h>

char *strdup(const char *s){
    char *copy;
    size_t l;

    if(NULL == s){
        return NULL;
    }

    copy=(char *) malloc(strlen(s)+1);
    return strcpy(copy,s);
}
