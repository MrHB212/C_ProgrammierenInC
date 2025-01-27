#include <stdio.h>

int main (void){
    int buchstaben[26] = { };
    char wort[60];
    int b2 = 65;
    int b = 65;
    fgets (wort, 60, stdin);

//Buchstaben zählen
for (int x = 0; x !=60; ++x){
    for (int z = 0; z != 26; ++z){
        if(wort[x]==b){
            buchstaben[b-65] += 1;
        }
        b += 1;
    }
    b = 65;
}

//Ausgagbe
for (int y = 0; y != 26; ++y){
    printf("%c: %d\n", b2, buchstaben[y]);
    b2 = b2+1;
}

}