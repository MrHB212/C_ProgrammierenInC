#include <stdio.h>

int f_rek(int x)
{
    if (x == 0)
    {
        return 1;
    }
    else
    {
        return f_rek(x / 2) * 2;
    }
}

int f_it(int x){

    int c=0;
    double r = 0.5;

    while(x!=0){
        ++c;
        x = x/2;
    }  

    for(int a = 0; a<c+1; ++a){
        r = r*2;
    }

    return r;
}

int g_rek(int *a, int n, int m)
{
    if (m == n - 1)
    {
        return a[n - 1];
    }
    else
    {
        return a[m] + g_rek(a, n, m + 1);
    }
}

int g_it(int *a, int n, int m)
{
    int r = a[m];

    if(m!=n-1){
        while(m!=n-1){
            m++;
            r += a[m];
        }
        return r;
    }else{
        return a[n-1];
    }


    
}

int main(void)
{
    int a[10] = {0};
    for (int i = 0; i < 10; i++)
    {
        printf("%d = %d\n", f_rek(i), f_it(i));
    }

    for (int i = 0; i < 10; i++)
    {
        a[i] = i;
        printf("%d = %d\n", g_rek(a, 10, 0), g_it(a, 10, 0));
    }

    return 0;
}