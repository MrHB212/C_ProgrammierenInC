#include <stdio.h>
#include <assert.h>
#include <stdint.h>
#include<math.h>
 
uint64_t to_bits ( double x)
{
// Check , dass double durch 64 Bit repraesentiert wird
assert ( sizeof ( double ) == sizeof ( uint64_t )) ;
return *( uint64_t *) &x;
}
 
int main(void){ 
     
int i=0 ; 
 
int e,l,k;  
float expo;
double fs;
 
    double a = 0;
    unsigned long long A = 0;
    int array[64] = {0};
    scanf("%lf", &a);
    fs=a;
    A = to_bits(a);
    //printf("%llu",A);
    
    for(int b = 63; b!=0; --b){
        array[b] = A%2;
        A = A/2;
    }
 
    if(a<0 || a==-0.0){
        array[0] = 1;
    }
 
    
 
// array ist die Binärdarstellung von a 
printf("Binary: ");
printf("%d ",array[0]);
for (i=1;i<=11;i++)
printf("%d",array[i]);
printf(" ");
for (i=12;i<=63;i++)
printf("%d",array[i]);
//sign von a 
 
printf("\nSign: %d\n",array[0]);
 
expo=0; 
//Ausgabe der Exponent
for (l=11,k=0;l>=1;k++,l--) 
expo= expo + array[l] * pow(2,k) ; 
e=expo;
printf("Exponent: %d\n", e) ; 
unsigned long long man = 0;  for(int x = 63; x!=11;--x){
        man = man + array[x] * pow(2, 63-x);
    }
   
 
 
 
 
printf("Mantisse: %llu\n", man) ; 
 
 
printf("Flip sign: %.4f\n", fs*-1.0) ;
 
 
 
if (!(expo=2047) && (man))
printf("Is nan"); else printf("Is not nan");
 
int summe=0 ; 
int p=0; 
for (p=0;p<=63;p++) {
    if (array[p]) 
    summe=summe+1;
    
}
printf("\nBinary representation has %d bits set\n", summe) ;
 
return 0 ; 
}