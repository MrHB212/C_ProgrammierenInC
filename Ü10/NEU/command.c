#include "globals.h"
#include <stdio.h>
#include <math.h>
#include <string.h>

void next_command(char *command_char, int *line_no, char text[])
{
    char input[LINE_LENGTH+6] = {0}; //Array wo die Eingabe abgespeichert wird
    int Z = 1; //Wird zum bestimmen von Indizes von Arrays verwendet
    int Y = 0; //Wird zum bestimmen von line_no verwendet
    int X = 0; //Wird beim Befehl i als Index verwendet

    fgets(input, LINE_LENGTH, stdin); //Eingabe einlesen
    *command_char = input[0]; //Befehl ist das erste Zeichen der Eingabe
    

    //Je nachdem was der erste Buchstabe also der Befehl ist wird das jeweilige if ausgeführt

    if(*command_char==100){ //d
       for(int a = 1; a!=10; ++a){
           if(input[a] > 47 && input[a] < 58){
               Y =  Y*10 + (input[a]-48);
               *line_no = Y;
           }
       }

        
        text[0] = '\0';
    }

    if(*command_char==105){ //i
        for(int a = 1; a!=4; ++a){
           if(input[a] > 47 && input[a] < 58){
               Y =  Y*10 + (input[a]-48);
               *line_no = Y;
               Z +=1;
           }
       }

        
        for(int b=1+Z; b<strlen(input);++b){
            if(input[b] != '\0' && input[b]!=10){
            text[X] = input[b];
            ++X;
            }else{
                text[X] = '\0';
                b = strlen(input)+10;
            }
        }
    }

    if(*command_char==112){ //p
        
        for(int a = 1; a!=10; ++a){
           if(input[a] > 47 && input[a] < 58){
               Y =  Y*10 + (input[a]-48);
               *line_no = Y;
           }
       }
       text[0] = '\0';
    }

   
    if(*command_char==113){ //q
        *line_no = 0;
        text[0] = '\0';
        
    }

    if(*command_char==114){ //r
         *line_no = 0;
         text[0] = '\0';
    }
}


/*

< = 60
> = 62

d<row>          Lösche Zeile <row>
i<row>/<text>   Füge eine Zeile <row> mit dem Text <text> ein
p bzw. p<row>   Drucke den gesamten Text bzw. die Zeile <row> auf dem Bildschirm aus
q               Editor beenden (quit)
r               Daten zurucksetzen (reset)
*/