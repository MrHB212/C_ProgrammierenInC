#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

// Das Programm zaehlt, wie hauefig jede Ziffer von 0 bis 9 in einer eingegebenen Zahl vorkommt.
int main(void)
{
    int x = 0;
    int i = 0;
    int count[10] = {0};

    // Einlesen der Eingabe
    scanf("%d", &x);
    printf("Hier ist ein Breakpoint zum lesen der Eingabe");
    // Zaehlen der Hauefigkeit
    while (x != '\0')
    {
        if (x == i)
        {
            count[i]++;
        }
        x++;
        i++;
        printf("Hier ist ein Breakpoint zum lesen der Variablen am Ende jedes Durchgangs");
    }
    // Ausgabe
    for (i = 0; i < 10; i++)
    {
        printf("%d: %d\n", i, count[i]);
    }

    return 0;
}