#include <stdio.h>
#include <math.h>

int main (){
    double eingabe = {0};
    int vorzeichen = {0};
    int exponent[11] = {0};
    int mantisse[52] = {0};
    int array[64] ={5};

    int KommaVerschiebung = -1;

    scanf("%lf", &eingabe);
    
    //Vorzeichen
    if (eingabe<0 || eingabe==-0){
        vorzeichen = 1;
        eingabe = eingabe * -1;
    }else{
        vorzeichen = 0;
    }
    
    //Exponent
    int vorkomma = eingabe; //Schneidet Nachkommastellen weg
    //Kommaverschiebung bestimmen
    for(int a = vorkomma; a !=0 ; a = a/2){
        if(a%2 == 0 || a%2 == 1){
            ++KommaVerschiebung;
        }
    }

    //Exponent
    int b = 10;
    int c = 1023+KommaVerschiebung;
    if(eingabe != 0 && eingabe != -0){
         while(b!=-1){
          exponent[b] = c%2;
            c = c/2;
         --b;
        }
    }

    //Mantisse
    int x = vorkomma;
    for(int d=KommaVerschiebung-1; x/2 != 0; --d ){
            mantisse[d] = x%2;
            x = x/2;
    }

    double f = eingabe - vorkomma;
    for(int e = 9; e !=52; ++e){
        f = f*2;
        mantisse[e] = f;
        if(f>=1){
            f=f-1;
        }
    }

    //Array zusammensetzen
    array[0] = vorzeichen;
    //1-11
    for(int xy = 1; xy !=12; ++xy){
        array[xy] = exponent[xy-1];
    }
    //12-63|0-52
    for(int xy = 12; xy != 64; ++xy){
        array[xy]=mantisse[xy-12];
    }

    //Ausgabe
    for(int xz = 0; xz != 64; ++xz){
        printf("%d", array[xz]);
    }

   
}

/*
Double: Vorzeichen + 11 bit Exponent + 52 bit Mantisse (63/52-62/0-51)

Komma = .
*/