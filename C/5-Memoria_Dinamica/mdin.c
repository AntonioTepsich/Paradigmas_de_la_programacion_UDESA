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
char *cop_izq(char *s1,int n){
    char *result;
    int i;
    for(i=0;i<n;i++){
        if(s1[i]!=' '){
            break;
        }
    }
    result=malloc(n-i*1);
    for(int j=0;i<n;j++,i++){
        result[j]=s1[i];
    }
    if(result==NULL){
        printf("no se recomienda");
        return NULL;
    }
    return result;

}
char *cop_der(char *s3,int n){
    char *result2;
    int i;
    for(i=0;i<n;i++){
        if(s3[n-i-2]!=' '){
            break;
        }
    }
    result2=malloc(n-i);
    for(int j=0;j<(n-i-1);j++){
        result2[j]=s3[j];
    }
    if(result2==NULL){
        printf("no se recomienda");
        return NULL;
    }
    return result2;
}

char *cop_cen(char *s5,int p){
    char *result3;
    int i,j;
    for(i=0;i<p;i++){
        if(s5[p-i-2]!=' '){
            break;
        }
    }
    for(j=0;j<p-i-1;j++){
        if(s5[j]!=' '){
            break;
        }
    }
    result3=malloc(p-i-j);
    int i2=i;
    for(int j2=0;j2<(p-i-j-1);j2++,i2++){
        result3[j2]=s5[i2];
    }
    if(result3==NULL){
        printf("no se recomienda");
        return NULL;
    }
    return result3;
    
}

void cuatro(){
    //---------a-----------
    char s1[]="     la izquierda  ";
    char *s2;
    s2=cop_izq(&s1,sizeof(s1)/1);
    printf("Palabra vieja: '%s'\nPalabra nueva: '%s'\n",s1,s2);
    free(s2);
    //---------b-----------
    char s3[]="  la derecha       ";
    char *s4;
    s4=cop_der(&s3,sizeof(s3)/1);
    printf("Palabra vieja: '%s'\nPalabra nueva: '%s'\n",s3,s4);
    free(s4);
    //---------c-----------
    char s5[]="     el centro     ";
    char *s6;
    s6=cop_cen(&s5,sizeof(s5)/1);
    printf("Palabra vieja: '%s'\nPalabra nueva: '%s'\n",s5,s6);
    free(s6);

}

char *centrado(char *s1,char s,int l){
    char *result,*aux;
    int i;
    aux=malloc((l-strlen(s1))/4+1);
    for(i=0;i<=(l-strlen(s1))/4;i++){
        aux[i]=s;
    }
    result=malloc(l+strlen(aux)*2+1);
    strcpy(result,aux);
    strcat(result,s1);
    strcat(result,aux);
    free(aux);
    return result;
}

void cinco(){
    char s1[]=" cadena ";
    char *s2;
    int n=12;
    if((strlen(s1)%2==0 && n%2==0) || (strlen(s1)%2!=0 && n%2!=0)){
        s2=centrado(&s1,'*',n);
        printf("Palabra '%s' '%c' '%i' --> '%s'\n",s1,'*',n,s2);
        free(s2);
    }
    else{
        puts("Los dos parametros deben ser impares o pares");
    }


}

char *inv_strox(int s1){
    char *resutl;
    int digitos;
    digitos= (log10(s1) + 1);
    resutl=malloc(digitos+1);
    sprintf(resutl,"%d",s1);
    return resutl;
}

void seis(){
    int s1=1234556;
    char *s2;
    s2=inv_strox(s1);
    printf("numero en forma de char: '%s'\n",s2);
    free(s2);
}

double * linspace(double inicio, double fin, size_t nelems){
    int i;
    double *result;
    result=malloc(nelems*sizeof(double));
    for(i=0;i<nelems;i++){
        result[i]=inicio+(i+1)*(fin-inicio-2)/nelems;
    }
    return result;
}

void once(){
    double *s2;
    int i;
    s2=linspace(6,16,4);
    printf("%i numeros entre %d y %d son:\n",4,6,16);
    for(i=0;i<4;i++){
        printf("%.2f\n",s2[i]);
    }
    free(s2);
}

int *concat_vector(int *s1,int i,int *s2,int j){
    int *result,k;
    result=malloc((j+i)*4+1);
    for(k=0;k<i;k++){
        result[k]=s1[k];
    }
    for(int m=0;m<j;m++,k++){
        result[k]=s2[m];
    }
    return result;
}

void doce(){
    int s1[]={1,2,3};
    int s2[]={4,5,6};
    int *s3;
    s3=concat_vector(&s1,3,&s2,3);
    printf("La union de s1 y s2 es:\n{");
    printf("%i",s3[0]);
    for(int i=1;i<6;i++){
        printf(" %i",s3[i]);
    }
    printf("}\n");
    free(s3);
}

int *modif_vector(int *s1,int i,int *s2,int j){
    int *result;
    result=malloc(i+1);
    result=realloc(result,(i+j)*4+1);
    int j2=0,i2;
    for(i2=0;i2<i;i2++){
        result[i2]=s1[i2];
    }
    for(i2;i2<i+j;j2++,i2++){
        result[i2]=s2[j2];
    }
    return result;
}

void trece(){
    int s1[]={1,2,3};
    int s2[]={4,5,6};
    int *s3;
    s3=modif_vector(&s1,3,&s2,3);
    printf("s1 ahora es:\n{");
    printf("%i",s3[0]);
    for(int i=1;i<6;i++){
        printf(" %i",s1[i]);
    }
    printf("}\n");
    free(s3);
}

int main(){

    // ----------Funciones con cadenas-----------

    // uno();
    // dos();
    // tres();
    // cuatro();    
    // cinco(); 
    // seis();
    // siete();   //falta
    //ocho();   //falta
    //nueve(); //falta
    //diez();   //falta

    // ----------Funciones con vectores y matrices-----------
    // once();
    // doce();
    trece();
    //catorce();   //falta   
    // quince();    //falta  
    // dieciseis();  //falta
    return EXIT_SUCCESS;
}