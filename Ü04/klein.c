#include <stdio.h>
#include <ctype.h>

int main(void){
    char eingabe = getchar();
    int ausgabe;
    
    //Eingabe ist Zahl oder Buchstabe ?
    if(isdigit(eingabe)){
        printf("Fehler: Kein Buchstabe");
    }
    else{
        //Groß- oder kleinbuchstabe ?
        if((eingabe >= 97) && (eingabe <=122)){
            //Eingabe ist Kleinbuchstabe
            ausgabe = eingabe - 32;
            printf("%c", ausgabe);
        }
        else{
            //Eingabe ist Großbuchstabe
            printf("%c", eingabe);
        }
    }
}
