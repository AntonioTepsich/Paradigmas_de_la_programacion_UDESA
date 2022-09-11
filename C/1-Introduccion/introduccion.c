#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void veintidos(int p){
    int i, contador=0;
    for(i=1;i<p;i++){
        if(p%i==0) contador++;
    }
    if(contador>1) put("No\n"); //false
    else put("Si\n");  //true
}

void veintitres(int x,int y){
    if(x>y) printf("%i es mayor que %i\n",x,y);
    else if(x<y) printf("%i es mayor que %i\n",y,x);
    else printf("%i y %i son iguales\n",y,x);
}

void veinticuatro(int i){
    if(i<0){
        i= -i;
    }
    printf ("%i",i);
}

void veinticinco(){
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

void veintiseis(float a,float b, float c,float h){
    float d=b*b-4.00*a*(c-h);
    float result1=(-b+sqrt(d))/(2*a);
    float result2=(-b-sqrt(d))/(2*a);

    printf("Las raices de %.2fx^2+%.2fx+%.2f=%.2f son: %.2f y %.2f\n",a,b,c,h,result1,result2);
}

void veintisiete(float a,float b, float c,float d){
    float x=(d-b)/(a-c);
    float y=a*x+b;

    printf("Las rectas %.2fx+%.2f y %.2fx+%.2f se intersectan en: X=%.2f - Y=%.2f\n",a,b,c,d,x,y);
}

void veintiocho(int x){
    if(x%4==0 && x%100!=0 && x%400!=0){
        printf("%i es bisiesto\n",x);
    }
    else{
        printf("%i no es bisiesto\n",x);
    }
}

void veintinueve(int x){
    int u,d,c;
    u=(x%100)/10;
    d=((x-u)%1000)/100;
    c=((x-u-d)%10000)/1000;

    printf("%i ARS = (%ix1000 ARS + %ix100 ARS + %ix10 ARS)\n",x,c,d,u);
}

void treinta(char a){
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

void treintayuno(){
    /*
    Tipos nativos:
        char (1 byte)         -128/127
        unsigned char (1 byte)         0/255
        short (2 bytes)       -32768/32767 #lo que yo represento puede tener signo
        int (4 bytes)         -2³¹/ 2³¹-1
        unsigned int (4 bytes)         0 / 4,294,967,295
        unsigned long (8 bytes)         0 / 18,446,744,073,709,551,615
        long int (8 bytes)     -2⁶³/ 2⁶³-1
        float (4 bytes)      +/- 1,8*10⁻⁺³⁸
        double (8 bytes)       +/- 1,8*10⁻⁺³⁰⁸
    */
}

void treintaydos(){
    /*
    a) 4 bytes 
    b) 
    */
}

void treintaytres(){
    
}

void treintaycutro(){
    /*
    6 es un int
    '6' estamos hablando del caracter 6
    "6" es un string
    */
}

void treintaycinco(){
    #define M_PI 3.14159265358979
    #define STR_HOLA_MUNDO "Hola mundo"
    #define NOTA_MAX 10
    #define NOTA_MIN_APROBADO 4
    #define SEGxHORA 3600
}

void treintayseis(){
    
}

void treintaysiete(){
    // float M_PI=3.14159; // no se puede re definir
    printf("%f\n",M_PI);
}

void treintayocho(int nota){
    if(nota==NOTA_MAX){
        printf("si\n");
    }
    else{
        printf("no\n");
    }
}

void treintaynueve(int r,float f){
    printf("entero: %i\nreal: %f\n",r,f);
}

void cuarenta(){
    /*
    printf ("El producto de %d y %d es %d"\n, x, y, z);

    suma=a + b;

    */

    /* Programa para obtener el máximo */ 

    /*

    if (numero >= maximo);

    printf ("El resto de dividir %d por %d es %d\n", numerador, denominador, numerador % denominador);

    if (x == y) printf ("%d es igual a %d\n", x, y);

    printf ("La suma da %d\n", x + y);
    */
}

void cuarentayuno(char a){
    printf("%c\n",a);
}
 
void cuarentaydos(int i,char a,int b,char c,char d,char e){
    printf("%c\n",b-c);
    printf("%c\n",d-e);
    if(a==i){
        printf("si\n");
    }
    else{
        printf("no\n");
    }
}
 
void cuarentaytres(){
    #include <limits.h>
    printf("INT_MIN: %i\n",INT_MIN);
    printf("INT_MAX: %i\n",INT_MAX);
    printf("RAND_MAX: %i\n",RAND_MAX);
    printf("UINT_MAX: %i\n",UINT_MAX);
}
 
void cuarentaycutro(){
    char nombre[20];
    char apellido[20];
    char num[20];
    int i,j;

    printf("INGRESE NOMBRE (max 20 digitos):\n");
    fgets(nombre,20,stdin);
    printf("\n");

    printf("INGRESE APELLIDO (max 20 digitos):\n");
    fgets(apellido,20,stdin);
    printf("\n");

    printf("INGRESE numero(max 20 digitos):\n");
    fgets(num,20,stdin);
    printf("\n");
    
    printf("nombre: ");
    j=strlen(nombre);
    for(i=0;i<=j;i++){
        printf("%c",nombre[i]);
    }
    printf("apellido: ");
    j=strlen(apellido);
    for(i=0;i<=j;i++){
        printf("%c",apellido[i]);
    }
    printf("numero: ");
    j=strlen(num);
    for(i=0;i<=j;i++){
        printf("%c",num[i]);
    }
}
 
void cuarentaycinco(char a){
    char a[10]="3.1415";
    printf("%.2f\n",M_PI);
    printf("%.3f\n",M_PI);
    printf("%f\n",M_PI);
    printf("%s\n",a);
}

void cuarentayseis(char a){
    #include <stdbool.h>
    //true=1 || false=0}
}

void cuarentaysiete(){

}

void cuarentayocho(){

}

void cuarentaynueve(){

}

void cincuenta(float a){
    printf("De %.2f: su inversa es %.2f y su raiz %.2f\n",a,-a,sqrt(a));
}

void cincuentayuno(int i){
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

void cincuentaydos(int i){
    int h,m,s;
    h=i/3600;
    i=i%3600;
    m=i/60;
    s=i%60;
    printf("Hora: %i - Min: %i - Seg: %i\n",h,m,s);
}


int main(){

// ----------Inicio-----------

// ----------Programas sencillos: Ciclos-----------

// ----------Programas sencillos: Decisiones-----------

    // veintidos(5);
    // veintitres(5,5);
    // veinticuatro(-4);
    // veinticinco();
    // veintiseis(1.00,4.00,1.00,2.00);
    // veintisiete(-2.00,1.00,3.00,6.00);
    // veintiocho(1905); //solo A
    // veintinueve(2320);
    // treinta('M');

// ----------Entendiendo C-----------

    // treintayuno();
    // treintaydos();
    // treintaytres(); //falta
    // treintaycutro();
    // treintaycinco();
    // treintayseis(); //falta
    // treintaysiete();
    // treintayocho(4);
    // treintaynueve(24,2.3);
    // cuarenta();
    // cuarentayuno('A');
    // cuarentaydos(4,'4','3','8','a','b');
    // cuarentaytres();
    // cuarentaycutro();
    // cuarentaycinco();
    // cuarentayseis();
    // cuarentaysiete();    //falta
    // cuarentayocho();    //falta
    // cuarentaynueve();    //falta

// ----------Interactuando con el usuario-----------

    // cincuenta(4.00);
    // cincuentayuno(294);
    // cincuentaydos(3650);
    // cincuentaytres();   //falta
    // cincuentaycuatro();   //falta
    // cincuentaycinco();   //falta
    // cincuentayseis();   //falta
    // cincuentaysite();   //falta
    // cincuentayocho();   //falta
    // cincuentaynueve();   //falta

    return EXIT_SUCCESS;
}