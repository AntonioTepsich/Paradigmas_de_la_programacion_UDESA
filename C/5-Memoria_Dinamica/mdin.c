#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

char *concat(char *s1,char *s2){
    char *result;
    result=malloc(strlen(s1)+strlen(s2)+1);
    if(result==NULL){
        printf("no se recomienda");
        return NULL;
    }
    strcpy(result,s1); //hago copia de s1 en result
    strcat(result,s2); //la concateno con s2
    printf("%s",result);
    return result;
}


void uno(){
    char s1[]="Antonio ";
    char s2[]="Tepsich";
    char*s12;
    s12=concat(s1,s2);
    printf("%s\n",s12);
    free(s12);
}

int *juntar(int *s1,int *s2){
    int *aux;
    aux=malloc(40);
    for(int i=0;i<6;i++){
        aux[i]=s1[i];
    }
    for(int i=0;i<4;i++){
        aux[i+6]=s2[i];
    }
    return aux;
}

void dos(){
    int s1[]={1,2,3,4,5,6};
    int s2[]={7,8,9,10};
    int *resultado;
    resultado=juntar(&s1[0],&s2[0]);
    for(int i=0;i<10;i++){
        printf("%i ",resultado[i]);
    }
    free(resultado);
}

char *copia(char *s2,int cont){
    char *result;
    result=malloc(cont);
    if(result==NULL){
        printf("no se recomienda");
        return NULL;
    }
    strcpy(result,s2); //hago copia de s1 en result
    return result;
}

void tres(){
    int i,cont=0;
    char s1[]="Hola Mundo;como va?";
    char s2[sizeof(s1)];
    for(i=0;i<sizeof(s1);i++){
        if(s1[i]!=';'){
            s2[i]=s1[i];
            cont+=1;
        }
        else break;
    }
    char *s12; 
    s12=copia(&s2[0],cont);
    printf("%s\n",s12);
    free(s12);
}

int main(){

    // ----------Funciones con cadenas-----------

    //uno();
    //dos();
    //tres();
    // cuatro();    //falta    
    // cinco();    //falta    
    // seis();    //falta
    //cuatro();   //falta
    //cinco();   //falta
    //seis();   //falta
    //siete();   //falta
    //ocho();   //falta
    //nueve(); //falta
    //diez();   //falta

    // ----------Funciones con vectores y matrices-----------


    return EXIT_SUCCESS;
}