#include <stdio.h>
#include <math.h>

int main (void) {
/*
0 = 0
1 = 1
2 = 2
3 = 3
4 = 4
5 = 5
6 = 6
7 = 7
8 = 8
9 = 9
A = 10

20 = Stopp
*/

int eingabe = 0;
int division[21] = { };
char ausgabe[21] = { };
int ergebnis = 0;

//Eingabe
scanf("%d", &eingabe);
ergebnis = eingabe;

//Umrechnung
for(int a = 0; a != 20; ++a){
    if(ergebnis-(ergebnis%11)*2 == 0){
        division[a] = 20;
    }else{
        division[a] = ergebnis % 11;
        ergebnis = ergebnis / 11;
    }
    
}

//Umwandlung von Divisionsergebnisse in Basis11
for(int b=0; b!=20; b++){
    switch(division[b]){
        case 0:
        ausgabe[b]='0';
            break;
        case 1:
            ausgabe[b]='1';
                break;
        case 2:
            ausgabe[b]='2';
                break;
        case 3:
            ausgabe[b]='3';
                break;
        case 4:
            ausgabe[b]='4';
                break;
        case 5:
            ausgabe[b]='5';
                break;
        case 6:
            ausgabe[b]='6';
                break;
        case 7:
            ausgabe[b]='7';
                break;
        case 8:
            ausgabe[b]='8';
                break;
        case 9:
            ausgabe[b]='9';
                break;
        case 10:
            ausgabe[b]='A';
                break;
        case 20:
            ausgabe[b]='X';
                break;
    }
}

//Ausgabe
printf("In Basis 11: ");
for(int c=20; c!=-1; --c){
    if(ausgabe[c] != 'X' && ausgabe[c] != '\0'){
        printf("%c", ausgabe[c]);
        }
    }
    
}