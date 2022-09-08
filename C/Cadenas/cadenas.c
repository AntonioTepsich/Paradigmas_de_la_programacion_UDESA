#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

/*
----------1---------
una cadena es un arreglo de caracteres.

----------2---------
los arreglos son variables estructuradas, donde cada elememto se almacena de forma consecutiva en memoria.
una cadena es un arreglo de caracteres que permite cierto numero de notaciones y funciones especiales.

----------3---------
el caracter '\0' sirve para darle un valor final a la cadena

----------4---------

*/

void cuatro(){
    char a[30]={'9', '5', '1', '1', '\n', '7', '5', '0', '2', '\0', 'R', 'u', 'L', 'Z', '\0', 'a', ' ', 'v', 'e', 'c', 'e', 's'};

    //empieza en '9'                                termina en '\0'
    printf("%s \n",a);
}

void cinco(){
    char a1[]={"Winter is coming"}; //a1 y a2 son arreglos de igual tamaño (17 bytes), pero escritos de diferentes formas
    char a3[]={'W','i','n','t','e','r',' ','i','s',' ','c','o','m','i','n','g','\0'};
    char a2[40]={"Winter is coming"}; //a3 es un arreglo de 40 chars que en los primeros 17 almacenan la cadena

    printf("a1: %s \n",a1);
    printf("a2: %s \n",a2);
    printf("a3: %s \n",a3);

}

void seis(){
    char manzana[] = "manzana"; //cadena
    char * naranja = "naranja"; //puntero

    char * frutas[] = {"uva", "kiwi", "caqui", "higo", "pera", "frambuesa"}; 
    char fruta[][10] = {"uva", "kiwi", "caqui", "higo", "pera", "frambuesa"}; //un arreglo con 6 cadenas de 10 byts


}

void siete(){
    char a[100];
    if(NULL!=fgets(a,100,stdin)){
        printf("%s\n",a);
    }
}

void ocho(){
    char a[100];

    printf("ingrese la cadena: ");
    if(fgets(a,100,stdin)!=NULL){
        for(int i=0;i<strlen(a)-1;i++){
            printf("%i   %c   %d\n",i,a[i],a[i]);
        }
    }
}

void diez(){
    char a[100];
    printf("ingrese la cadena: ");
    if(fgets(a,100,stdin)!=NULL){
        if(strlen(a)==1){
            printf("esta vacia\n");
        }
        else{
            printf("%s\n",a);
        }
    }

}
size_t strle(const char *inicio){
    const char *final=inicio;

    for (; *final!='\0'; ++final){
    }
    return (final - inicio);
}
char * strcpy(char *dest, const char *orig){

}
void once(){
    char st[30]={"holas"};
    //strle(st);
    printf("%li\n",strle(st));
}

void doce(){
    char a[]="Fire and blood.",b[]="~!@#$^*()_+|]{:,<z";
    printf("%s\n%li\n",a,strlen(a)+1);
    printf("%s\n%li\n",b,strlen(b)+1);
    //fgets(a,100,stdin);
}
void invertir(char *pal){
    char *inv=pal;
    for(int i=0;i<strlen(pal);i++){
        inv[i]=pal[strlen(pal)-i];
    }
    printf("%s\n",inv);
    //char copia[strlen(*pal)];
}
void trece(){
    char a[]="anto";
    invertir(&a);
}

int main(){
    //cuatro();
    //cinco();
    //seis();
    //siete();
    //ocho();
    //diez();
    //once();
    //doce();
    trece();


    return EXIT_SUCCESS;
}
