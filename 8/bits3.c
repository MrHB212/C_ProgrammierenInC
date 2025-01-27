#include <assert.h>
#include <stdint.h>
#include <stdio.h>
#include <math.h>

uint64_t to_bits (double x){
// Check , dass double durch 64 Bit repraesentiert wird
assert (sizeof(double) == sizeof(uint64_t));
return *(uint64_t *)&x;

}

int main(){
    double eingabe = 0;
    unsigned long long A = 0;
    int array[64] = {0};
    scanf("%lf", &eingabe);
    A = to_bits(eingabe);
    //printf("%llu",A);
    unsigned long long mantisse = 0;
    
    for(int a = 63; a!=0; --a){
        array[a] = A%2;
        A = A/2;
    }

    if(eingabe<0){
        array[0] = 1;
    }

    for(int a = 0; a!=64; ++a){
        printf("%d", array[a]);
    }

    //63-12
    for(int x = 63; x!=11;--x){
        mantisse = mantisse + array[x] * pow(2, 63-x);
    }
    printf("\n%llu", mantisse);

    if(eingabe == -0){
        printf("\npositive");
    }



    
    
}