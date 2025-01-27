#include <stdio.h>

int main(void){
    int n = 0;
    double divisor = 0;
    double ergebnis = 0;

    scanf("%d", &n);

//Fall 1: Eingabe = 0
    if (n==0){
        ergebnis = 1.0;
        printf("%-12.8f", ergebnis);
    }

//Fall 2: Eingabe ist positiv
    if (n>0){
        divisor = 2;
        for(int i=1; i<n; i++) {
            ergebnis = 1/divisor;
            printf(" %-11.8f|", ergebnis);
            divisor = divisor * 2;
        }
        ergebnis = 1/divisor;
        printf("%11.8f", ergebnis); //Letzte Ausgabe ohne |
    }

//Fall 3: Eingabe ist negativ
    if (n<0){
        ergebnis = 2;
        for(int i=-1; i>n; i--) {
            printf(" %-11.8f|", ergebnis);
            ergebnis = ergebnis * 2;
        } 
        printf("%11.8f", ergebnis); //Letzte Ausgabe ohne |
    }
}