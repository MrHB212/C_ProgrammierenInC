#include <stdio.h>
#include <stdlib.h>

// Alloziert ein Array für n double-Werte und initialisiert es mit 0.0, 1.0, 2.0, etc.
double *make_array(int n)
{
    int i = 0;
    double *array = calloc(n, sizeof(double));
    if (array != NULL) // Allozieren von Speicher
    {
        for (i = 0; i < n; i++)
        {
            array[i] = i;
        }
    }
    return array;
}

int main(void)
{
    int i;
    int size;
    double *dp;
    scanf("%d", &size);
    dp = make_array(size);
    if (dp != NULL)
    {
        for (i = 0; i < size; i++) // Ausgeben der Werte
        {
            printf("%4.2f ", dp[i]);
        }
        printf("\n");
        free(dp); // Freigeben des Speichers
    }
    return 0;
}

/*
1 = Ein zweites free(dp) ist nicht möglich, da beim zweiten Mal dp schon freigegeben wurde
2 = scanf("%d, &size") -> scanf("%d", &size)
3 = Um einem Array Speicher zuzuweisen wird calloc verwendet, da das Array n Mal den selben Typ an Variablen speichert.

*/
