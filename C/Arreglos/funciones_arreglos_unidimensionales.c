#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void ceros(int c[], int n,int x){
    for (size_t i = 0; i < n; ++i) {
        c[i]=x;
        printf("%i\n",c[i]); 
    }
}



int main(void){
//-----------1----------
    int c[6]={0, 1, 2, 3, 10, 11};
    //ceros(c,sizeof(c)/4,0); //a
    //ceros(c,sizeof(c)/4,1); //b


//-----------2----------

//-----------3----------


//-----------4----------

//-----------5----------

//-----------6----------
    /*

    */
    return EXIT_SUCCESS;
}