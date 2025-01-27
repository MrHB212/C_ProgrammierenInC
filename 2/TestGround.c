#include<stdio.h>

int main(void)
{
    int x, y, z, m;
    scanf("%d", &x);
    scanf("%d", &y);
    scanf("%d", &z);

    if (x < y) {
        if (x < z) {
             m = x; }       
         else m = z;
     }else if  (y < z){
           m = y; }
        else m = z;

    printf("%d", m);
    return 0;
}