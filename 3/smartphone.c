#include <stdio.h>

int main (void){

    int tage = 0;
    printf("Bitte geben Sie Anzahl an Tage ein: ");
    scanf("%d", &tage);
    double kapazitaet = 3000*0.8;
    double spannung = 3.85;
    double watt = spannung * kapazitaet / 1000; //Watt = Volt * Ampere
    double kosten = tage * watt / 1000 * 0.3;
    
    if (tage <=0){
        printf("Tage k\x94nnen nicht 0 oder kleiner sein.");}
       else{
            printf("Die kosten f\x81r %d Tag(e) betragen %.4f Euro;", tage, kosten);
        }
    } 