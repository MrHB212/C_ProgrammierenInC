#include <stdio.h>
#include <math.h>

int main (){
    double eingabe = {0};
    int vorzeichen = {0};
    int exponent[11] = {0};
    int mantisse[52] = {0};
    double mantisseZahl = 0;
    //int setbits = 0;

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
    //printf("\nKommaverschiebung\n %d", KommaVerschiebung);

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



    //Ausgabe
    printf("Binary: ");
    printf("%d ", vorzeichen);

    for(int x = 0; x!=11;++x){
        printf("%d", exponent[x]);
    }

    printf(" ");

    for(int y = 0; y!=52;++y){
        printf("%d", mantisse[y]);
    }

    printf("\nSign: %d\n", vorzeichen);

    printf("Exponent: %d", (1023+KommaVerschiebung));
   

    
    for(int y = 51; y!=-1;--y){
        if(mantisse[y] == 1){
            mantisseZahl = mantisseZahl+pow(2, (51-y));
        }
    }

    printf("\nMantisse: %.0lf", mantisseZahl);


    printf("\nFlip sign: %.4f\n", (eingabe));

    if (!(1023+KommaVerschiebung==2047) && (mantisseZahl))
    printf("Is nan"); else printf("Is not nan");


   
}

/*
Double: Vorzeichen + 11 bit Exponent + 52 bit Mantisse (63/52-62/0-51)

Komma = .
*/