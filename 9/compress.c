#include <stdint.h>
#include <stdio.h>
#include <string.h>

#define MAX_TEXT_LENGTH 64

int compress(char *input, int input_size, uint16_t *output, int max_output_size);
int decompress(uint16_t *input, int input_size, char *output, int max_output_size);

int main(void)
{
    char text[MAX_TEXT_LENGTH] = {0};
    uint16_t compressed[MAX_TEXT_LENGTH] = {0};
    char result[MAX_TEXT_LENGTH] = {0};
    int n, m, k;

    fgets(text, MAX_TEXT_LENGTH, stdin);
    n = strlen(text); //Länge der Eingabe

    m = compress(text, n, compressed, MAX_TEXT_LENGTH); //Komprimierte Eingabe
    k = decompress(compressed, m, result, MAX_TEXT_LENGTH); //Dekomprimierte Eingabe

    if (n == k)
    {
        printf("%s\n", result);
    }
    else
    {
        printf("Fehler bei der Komprimierung!\n");
        printf("Eingabe: %s\n", text);
        printf("Ergebnis: %s\n", result);
    }
    return 0;
}

int compress(char *input, int input_size, uint16_t *output, int output_size){
    int B = 0;            //Wievieltes Zeichen
    int C = 0;            //Output Stelle
    int D = 0;            //Länge von output
    int w, x, y, z;       //Enthält Werte der Zeichen
    
    while(B<64){
        //3 Kleinbuchstaben nebeneinander
            if((input[B] > 96 && input[B] < 123) && (input[B+1] > 96 && input[B+1] < 123) && (input[B+2] > 96 && input[B+2] < 123)){
                x = ((input[B]-96) <<10) | 0x8000;
                y = ((input[B+1]-96) <<5) | 0x8000;
                z = (input[B+2]-96) | 0x8000;
                w = x | y | z;
                B +=3;
                output[C] = w;
                ++C;
            }else{
                x = (input[B]<<8) | 0x0000;
                y = input[B+1];
                z = x | y;
                output[C] = z;
                B +=2;
                C++;
            }
        
    }
    //Länge von output bestimmen
    for(int g = 0; g !=64; ++g){
        if(output[g] != 0){
            ++D;
        }
    }

    return D;
}

int decompress(uint16_t *input, int input_size, char *output, int output_size){
    int I = 0; //Index von input
    int O = 0; //Index von output
    int a, b, c, d;

    while(I<input_size){

        //Wenn 3 Kleinbuchstaben nebeneinander
        if(input[I] > 32767){
            d = input[I] - 32768;
            a = d & 0x001F;
            b = (d & 0x03E0) >> 5;
            c = (d & 0x7C00) >> 10;

            a += 96;
            b += 96;
            c += 96;

            output[O] = c; 
            output[O+1] = b; 
            output[O+2] = a; 

            I += 1;
            O += 3;
        
        }

        if(input[I]<32768){
            d = input[I];
            a = d >> 8;
            b = d & 0x007F;

            output[O] = a;
            output[O+1] = b;

            I += 1;
            O += 2;
        }

        
    }
    return strlen(output);
    
    
}

/*
aaa = (32) 97 97 97 32 = 1100001 1100001 1100001 -> 1 00001 00001 00001 - 33825 = 32768 + 1057
a = 97-1100001 -> 100001-1 => x.ter Buchstabe + 96
A = 65-1000001 -> 0100001-65 => Wert ändert sich nicht // AA = 4257

1000000000000000 = 32768 bis 65535 für aaa
0000000000000000 = 0 bis 32767 für rest

abc = 1 aaaaa bbbbb ccccc
*/