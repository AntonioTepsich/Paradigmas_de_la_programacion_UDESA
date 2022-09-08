#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>


const int ancho=10;
const int alto=10;
const int seed=2;



int main(void){
//-----------1----------
    int c[ancho][alto];
    srand(time(NULL));
    int i,n,s=0,f;
    int co,cont,cont2;
    
    printf("Inicio\n");
    for(size_t fila=0;fila<ancho; fila++){
        for(size_t col=0; col<alto; col++ ){
            for(size_t i=0;i<(10);i++){
                n=rand()%2;     
            }
            c[fila][col]=n;
            printf("%d",c[fila][col]);
        }
        printf("\n");
    }


    while(s<seed){  //cantidad de veces que se repite
        printf("Iteracion numero %i\n",(s+1));

        for(size_t fila=0;fila<ancho;fila++){  //genera ataques
            for(size_t col=0;col<alto;col++){
                cont=0;
                cont2=0;
                f=fila;
                co=col;
                if(c[f][co]==1){
                    if((f-1)>=0){
                        if(c[f-1][co]==1){
                            cont++;
                        }
                    } 
                    if((f+1)<ancho){
                        if(c[f+1][co]==1){
                            cont++;
                        }
                    } 
                    if(co-1>=0){
                        if(c[f][co-1]==1){
                            cont++;
                        }
                    } 
                    if(co+1<alto){
                        if(c[f][co+1]==1){
                            cont++;
                        }
                    }
                    if(f-1>=0 && co+1<alto){
                        if(c[f-1][co+1]==1){
                            cont++;
                        }
                    }
                    if(f-1>=0 && co-1>=0){
                        if(c[f-1][co-1]==1){
                            cont++;
                        }
                    }
                    if(f+1<ancho && co-1>=0){
                        if(c[f+1][co-1]==1){
                            cont++;
                        }
                    }
                    if(f+1<ancho && co+1<alto){
                        if(c[f+1][co+1]==1){
                            cont++;
                        }
                    }
                }
                else{
                    if((f-1)>=0){
                        if(c[f-1][co]==1){
                            cont2++;
                        }
                        
                    } 
                    if((f+1)<ancho){
                        if(c[f+1][co]==1){
                            cont2++;
                        }
                    } 
                    if(co-1>=0){
                        if(c[f][co-1]==1){
                            cont2++;
                        }
                    } 
                    if(co+1<alto){
                        if(c[f][co+1]==1){
                            cont2++;
                        }
                    }
                    if(f-1>=0 && co+1<alto){
                        if(c[f-1][co+1]==1){
                            cont2++;
                        }
                    }
                    if(f-1>=0 && co-1>=0){
                        if(c[f-1][co-1]==1){
                            cont2++;
                        }
                    }
                    if(f+1<ancho && co-1>=0){
                        if(c[f+1][co-1]==1){
                            cont2++;
                        }
                    }
                    if(f+1<ancho && co+1<alto){
                        if(c[f+1][co+1]==1){
                            cont2++;
                        }
                    }
                }

                if(cont<2){
                    c[f][co]=0;
                }

                else if(cont==2 || cont==3){
                    c[f][co]=1;
                }
                else if(cont>3){
                    c[f][co]=0;
                }
                if(cont2==3) c[f][co]=1;
            }
        }
        for(size_t fila=0;fila<ancho; fila++){
            for(size_t col=0; col<alto; col++ ){
                printf("%d",c[fila][col]);
            }
            printf("\n");
        }
        printf("\n");
        s++;
    }
   
//-----------2----------



//-----------3----------

//-----------4----------

//-----------5----------

//-----------6----------
    /*

    */
    return EXIT_SUCCESS;
}