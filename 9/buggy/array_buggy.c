#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define SIZE 20

int main(void)
{
    int ar[SIZE];
    int i = -1;

    while (i < SIZE)
    {
        i++;
        ar[i] = i;
        printf("Hier ist ein Breakpoint");
        i++;
    }

    for (i = 0; i < SIZE; i++)
    {
        printf("Position %d: %d\n", i, ar[i]);
    }
    return 0;
}