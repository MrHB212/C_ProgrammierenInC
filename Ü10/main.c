#include "command.h"
#include "globals.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int *max_line_no = 0;
char *text_field[LINE_COUNT][LINE_LENGTH] = {{'/0'}};

void copy_line(int to, int from){
    for(int a=0; a!=256; ++a){
        *text_field[to][a] = *text_field[from][a];
    }
}

void add_line(int line_no){
    for(int a=*max_line_no+1; a!=line_no; --a){
        for(int b=0; b!=256; ++b){
            *text_field[a][b] = *text_field[a-1][b];
        }
    }
    max_line_no +=1 ;
}

void delete_line(int line_no){
     for(int a=line_no+1; a!=*max_line_no+1; ++a){
        for(int b=0; b!=256; ++b){
            *text_field[a-1][b] = *text_field[a][b];
        }
    }
    *text_field[line_no][0] = '\0';
    *max_line_no -=1;
}

void print_text(void){
    for(int a=0; a!=*max_line_no+1; ++a){
        printf("%d   ", a+1);
        for(int b=0; b!=256; ++b){
            printf("%c", *text_field[a][b]);
        }
    }
}

void print_line(int line_no){
    printf("%d   ", line_no);
    for(int a=0; a!=256;++a){
        printf("%c", *text_field[line_no-1][a]);
    }
}

void insert(int line_no, char text[]){
    add_line(line_no-1);
    for(int a=0; a!=strlen(text); ++a){
        *text_field[line_no-1][a] = text[a];
    }
}

void erase(int line_no){
    delete_line(line_no-1);
}


int main(void)
{
    char command_char;
    int line_no;
    char text[LINE_LENGTH];
    

    while(1){
    next_command(&command_char, &line_no, text);

    switch(command_char){
        case 'd':
            erase(line_no);
            break;

        case 'i':
            insert(line_no, text);
            break;

        case 'p':
            if(line_no >0){
                print_line(line_no);
            }else{
                print_text();
            }
            break;

        case 'q':
            exit(0);
            break;
        case 'r':   
            for(int a=0; a!=1000;++a){
                text_field[a][0] = 0;
            }

    }
    }

    //printf("Kommando: '%c', %i, <%s>\n", command_char, line_no, text);
    return 0;
    
}
