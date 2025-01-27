#include <stdio.h>
int b(int n, int k);
int main (void){
    int a = 0;
    int c = 0;
    int r = 0;
    
    scanf("%d", &a);
    scanf("%d", &c);
    r = b(a,c);
    printf("Breakpoint");
}




int b( int n, int k)
{
    if (k == 0)
        return 1;
    if (k == n)
        1;
    if (k < n)
        return b(n -1 , k -1) + b(n -1 , k);
}