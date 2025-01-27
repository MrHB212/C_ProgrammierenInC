#include <stdio.h>
#define N = 10

int main (){
    int array1[11];
    int array2[11];
    int counter = 0;
    
    //Eingabe
    for(int i=0; i<10; ++i){
        scanf("%d", &array1[i]);
    }

    for(int l=0; l<10;++l){
        scanf("%d", &array2[l]);
    }

    //Check
    for(int a=0; a<10; ++a){
        for(int b=0; b<10; ++b){
            if(array1[b]==array2[a]){
                ++counter;
            }
        }

    }

    printf("%d", counter);
    return 0;

}