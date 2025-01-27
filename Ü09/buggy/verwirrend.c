#include <stdio.h>


int main ( void )
{
    struct
    {
        u_int32_t s1;
        u_int32_t s2;
    } s = {1 , 2};
    u_int32_t *sp = &s.s1;
    *(( u_int64_t *) sp) = 89;
    printf ("%d\n", s.s2) ; // Ausgabe 0
    return 0;
}