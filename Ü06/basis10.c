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
*/
char eingabe[21] = { };
fgets(eingabe, 21, stdin);

int index = 0;
double faktor = 0;
int dezimal = 0;

//Index der letzten Eingabe vor \0 finden
for(int n = 19; n !=-1; --n){
    if(eingabe[n]=='\0'){
        index = n-2;
    }
}

for(int m = index; m != -1; --m){
    faktor = pow(11, index-m);
    switch (eingabe[m])
    {
    case '0':
        dezimal = dezimal + 0 * faktor;
        break;
    
    case '1':
        dezimal = dezimal + 1 * faktor;
        break;

    case '2':
        dezimal = dezimal + 2 * faktor;
        break;

    case '3':
        dezimal = dezimal + 3 * faktor;
        break;

    case '4':
        dezimal = dezimal + 4 * faktor;
        break;

    case '5':
        dezimal = dezimal + 5 * faktor;
        break;

    case '6':
        dezimal = dezimal + 6 * faktor;
        break;

    case '7':
        dezimal = dezimal + 7 * faktor;
        break;

    case '8':
        dezimal = dezimal + 8 * faktor;
        break;

    case '9':
        dezimal = dezimal + 9 * faktor;
        break;

    case 'A':
        dezimal = dezimal + 10 * faktor;
        break;
    }
}


printf("In Basis 10: %d", dezimal);





}