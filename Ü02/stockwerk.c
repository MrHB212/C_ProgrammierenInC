#include <stdio.h>

int main(void){
//Einlesen der Eingabe in nummer
int nummer;
printf("Bitte Raumnummer eingeben: ");
scanf("%d", &nummer);

// Hier zu ergänzen: Ermitteln des Stockwerks und Ausgabe
printf("Stockwerk des eingegebenen Raumes: %d", nummer/100);

return 0;
}