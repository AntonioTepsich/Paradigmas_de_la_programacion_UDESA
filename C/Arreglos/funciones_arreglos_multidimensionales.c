#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void ceros(int c[][3], int n,int x){
    for (size_t i = 0; i < n; ++i) {
        for(size_t j=0;j<(sizeof(c[0])/sizeof(int));j++){
            c[i][j]=x;
            printf("%i",c[i][j]); 
        }
        printf("\n"); 
    }
}

void traza(int c[][3],int n){
    int tr=0;
    for(size_t i=0;i<n;i++){
        for(size_t j=0;j<(sizeof(c[0])/sizeof(int));j++){
            if(i==j) {
                tr+=c[i][j];
                //printf("%i\n",c[i][j]);
                break;
            }
        }
    }
    printf("traza = %i\n",tr);
}

int main(void){
    int c[3][3]={0, 1, 2, 3, 10, 11,12,4,8};
//-----------1----------
    //ceros(c,3,0); //a
    //ceros(c,3,1); //b

//-----------2----------



//-----------3----------
    traza(c,3);

//-----------4----------

//-----------5----------

//-----------6----------
    /*

    */
    return EXIT_SUCCESS;
}