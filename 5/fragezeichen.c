#include <stdio.h>

int main (void){
float anzahlF = 0;
float haeufigkeit = 0;
float index = 0;
char string[61] = { 0 };
fgets (string, 61, stdin);

//Index des zueltzt eingegebenen Zeichens
for (int n=0; n != 60; ++n){
    if(string[n] != 0){
        index = n;
    }
}


//Fragezeichen zählen
 for (int a=0; a !=60 ; a++){
    if(string[a]==63){
        ++anzahlF;
    }
}


//Ausgabe der Anzahl der Fragezeichen und dere Häufigkeit
printf("Der String \"%s\" enthaelt %.0f Fragezeichen.\n", string, anzahlF);
haeufigkeit = anzahlF / (index+1);
printf("Haeufigkeit: %.4f ", haeufigkeit);


}