#include <stdio.h>
//Korrektur der Aufgabe 2
int main(void)
{
    int x, y, z, m;
    printf("Bitte geben Sie nacheinander 3 ganze Zahlen ein und best\x84tigen Sie jeweils mit 'Enter'\n");
    scanf("%d", &x);
    scanf("%d", &y);
    scanf("%d", &z);
    
    m = z;

    if ( (x < y) && (x < z) ){
        m = x;
    }

    if ( (y < x) && (y < z) ){
        m = y;
    }
    

   printf("Die kleinste von Ihnen eingegebene Zahl ist: %i", m);
   return 0;
}
/*
Das programm wartet zunächst auf 3 Eingaben des Nutzers.
Danach werden den Variablen x, y und z jeweils die Eingaben als Wert zugewiesen.
Dabei nimmt m immer den Wert von z an.
Danach überprüft das Programm, ob x oder y die kleinste Zahl ist.
Falls dem so sein sollte, wird m der Wert von x oder y zugewiesen.
Falls dies nicht der Fall sein sollte, wird der Wert der Variablen m ausgegeben.

Dadurch, dass m immer den Wert von z annimmt, muss man nurnoch die Variablen x und y überprüfen.
man spart sich also einen Schritt.
*/

