#include <stdio.h>
#include "bubblesort.h"
#define MAX 60

void printarray(int arr[], int n)
{
    int i;
    for (i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main(void)
{
    int n = 0;
    int i = 0;
    int eingabe[MAX] = {0};
    scanf("%d", &n);

    if (n > MAX)
    {
        printf("Zu viele Elemente!\n");
        return 0;
    }

    for (i = 0; i < n; i++)
        scanf("%d", &eingabe[i]);

    bubblesort(eingabe, n);
    printarray(eingabe, n);
    return 0;
}