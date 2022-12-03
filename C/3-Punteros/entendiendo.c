#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>


void uno(){
    /*
    float * pfloat, manzana = 40.0, pera = 35.0;

    printf("&pfloat: %p\n", &pfloat);       direccion de memoria
    printf("&manzana: %p\n", &manzana);     direccion de memoria
    printf("&pera: %p\n", &pera);           direccion de memoria

    printf("pfloat: %p\n", pfloat);         valor almacenado

    pfloat = &manzana;
    printf("pfloat: %p\n", pfloat);         valor almacenado
    printf("*pfloat: %p\n", *pfloat);       40.0

    pfloat = &pera;                         
    printf("pfloat: %p\n", pfloat);         valor almacenado
    printf("*pfloat: %p\n", *pfloat);       35.0
    */
   float * pfloat, manzana = 40.0, pera = 35.0;

    printf("&pfloat: %p\n", &pfloat);
    printf("&manzana: %p\n", &manzana);
    printf("&pera: %p\n", &pera);

    printf("\n");

    printf("pfloat: %p\n", pfloat);

    printf("\n");

    pfloat = &manzana;
    printf("pfloat: %p\n", pfloat);
    printf("*pfloat: %f\n", *pfloat);

    printf("\n");

    pfloat = &pera;
    printf("pfloat: %p\n", pfloat);

    printf("\n");

    pera=80.00;
    printf("*pfloat: %f\n", *pfloat);
}


void dos(){
    int i = 3, * pint; //bien
    float f = 10.0;    //bien

    pint = &i;         //bien -la variable puntero pint contiene la direccion de memoria de la variable i
    *pint = 10;
    *pint = f;
    //pint = &f;        //no le puedo asignar un float a un int
    //pint = 4321;        //no le puedo asignar un valor a un punter
    printf("%p\n",pint);
    printf("%i\n",*pint);

}

void tres(){
//----------a---------
    float va, set[] = {1.0, 2.0, 3.0, 4.0, 5.0};
    float *s;

    s = set; //mal falta indicar la posicion con &set
    va = *s;
    *s=10.0;

//----------b---------
    int conj[5], list[]={5, 4, 3, 2, 1};
    int *punt;

    punt = list;
    //conj= punt;
    //list = conj;
    //punt = &conj;
    // printf("%i\n",*punt);

//----------c---------
    int *pint, arrayint[5];
    float *pfloat, arrayfloat[5];

    pint = arrayint; 
    pfloat = arrayfloat;
    pint += 1;  
    pfloat += 1;
    pint++;
    pfloat++;
    pint -= 1;
    pfloat -=1;
    // printf("%i\n",*pint);

//----------d---------
    int *p, a[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

    int var;
    p = a;
    // *p = 33;
    var = *p;
    var = *(p+1);
    var = *(p+3);
    var = *(p++);
    var = *p++;
    var = *(++p);
    var = *++p;
    var = ++*p;
    var = (*p)++;
    var = ++(*p);
    var = *p+1;
    // printf("%i\n",var);
}


void cinco(){
    int matriz[3][4] = { { 1, 2, 3, 4}, { 5, 6, 7, 8}, { 9,10,11,12} };
    int * ptr;
    int fila, col;

    ptr=&matriz[0][0];
    for(fila=0;fila<3;fila++){
        for(col=0;col<4;col++){
            printf("%i ",*(ptr+fila*4+col));
        }
        printf("\n");
    }
}

void swap(int *a, int *b){
    int aux=*a;
    *a=*b;
    *b=aux;
}

void seis(){
    int a=1,b=2;
    printf("a:%i b:%i\n",a,b);
    swap(&a,&b);
    printf("a:%i b:%i\n",a,b);
}
void suma(int a, int b, long int *sum){
    *sum=a+b;
}
void resta(int a, int b, long int *res){
    *res=a-b;
}
void producto(int a, int b, float *prod){
    *prod=a*b;
}
void division(float a, float b, double *div){
    *div=a/b;
}
void modd(int a,int b, long int *mod){
    *mod=a%b;
}
void siete(){
    long int sum,res,mod;
    float prod;
    double div;
    int a=5,b=3;
    suma(a,b,&sum);
    printf("%li\n",sum);
    resta(a,b,&res);
    printf("%li\n",res);
    producto(a,b,&prod);
    printf("%f\n",prod);
    division(a,b,&div);
    printf("%f\n",div);
    modd(a,b,&mod);
    printf("%li\n",mod);
}

void a_hms(int segundos,int *h,int *m, int *s){
    *h=segundos/3600;
    *m=(segundos%3600)/60;
    *s=(segundos%3600)%60;
}

void ocho(){
    int h,m,s,x=3666;
    a_hms(x,&h,&m,&s);
    printf("%ihs %im %is son %i segundos\n",h,m,s,x);
}

void implementar(int *v,int l,int x){
    for(size_t i=0;i<l;i++){
        *(v+i)=x;
    }
}

void nueve(){
    int v[]={1,2,3,4,5},l=sizeof(v)/4;

    //----------a---------
    implementar(&v[0],l,0);
    for(size_t i=0;i<l;i++){
        printf("%i ",v[i]);
    }
    //----------b---------
    implementar(&v[0],l,1);
    for(size_t i=0;i<l;i++){
        printf("%i ",v[i]);
    }
    //----------c---------

}

void veccpy(int *dest, size_t ldest, const int *orig, size_t lorig){
    if(ldest==lorig){
        for(size_t i=0;i<lorig;i++){
            printf("%i ",*(dest+i));
        }
        printf("\n");
        for(size_t i=0;i<lorig;i++){
            ((int *)dest)[i]=((int *)orig)[i];
        }
    }
    else{
        printf("no tienen el mismo tamano\n");
    }
}




void diez(){
    int v3[]={1,3},l1=sizeof(v3)/4,v4[]={1,2},l2=sizeof(v4)/4;
    veccpy(&v3[0],l1,&v4[0],l2);
    printf("Nuevo v3: ");
    for(size_t i=0;i<l1;i++){
            printf("%i ",v3[i]);
    }
    printf("\n");

}

void igual(int *dest, size_t ldest, const int *orig, size_t lorig){
    int f=0;
    if(ldest==lorig){
        for(int i=0;i<lorig;i++){
            if(*(dest+i)!=*(orig+i)){
                f=1;
                break;
            } 
        }
        if(f==1) printf("distintos\n");
        else printf("iguales\n");
    }
    else{
        printf("no tienen el mismo tamano\n");
    }

}

void once(){
    int v1[]={1,2},l1=sizeof(v1)/4,v2[]={1,2},l2=sizeof(v2)/4;
    igual(&v1[0],l1,&v2[0],l2);

}

const int * busqueda_lineall(const int *v, size_t n, int objetivo){
    for(size_t i=0;i<n;i++){
        if(v[i]==objetivo){
            return &v[i];
        }
    }
    return NULL; 
}

bool busqueda_lineal(int * v, size_t n, int objetivo, int **resultado){
    printf("entrada\n");
    for(size_t i=0;i<n;i++){
        printf("%li\n",i);
        if(v[i]==objetivo){
            resultado=&v;
            return true;
        }
    }
    return false;
}

void prueba(){
    int *resultado=NULL, *v=NULL,objetivo=4,a[]={3,4,5,6,7},b[]={4,5,6,7};
    v=&b[0];
    printf("entrada\n");
    busqueda_lineal(v,sizeof(b)/sizeof(b[0]),objetivo,resultado);
    printf("salida\n");
    printf("%p",resultado[0]);
}

void doce(){
    int v5[]={1,2},l1=sizeof(v5)/4;
    int obj=1;
    int *a;
    a[0]=*busqueda_lineall(v5,l1,obj);
    busqueda_lineall(v5,l1,2);
    printf("%i",*a);
}

int main(){

    // ----------Entendiendo punteros-----------

    // uno();
    //dos();
    // tres();
    // cuatro();  //falta
    // cinco();

    // ----------Funciones con punteros-----------

    // seis();
    // siete();
    //ocho();
    //nueve();
    //diez();
    //once();
    // doce();
    //trece();   //falta


    prueba();

    return 0;
}
