#include <stdio.h>
#include <stdint.h>

int main (void){
struct 
{
uint32_t s1;
uint32_t s2;
}
s = {1, 2};
uint32_t *sp = &s.s1;
*(( uint64_t *) sp) = 89;
printf ("%d\n", s.s2); // Ausgabe 0
return 0;

}