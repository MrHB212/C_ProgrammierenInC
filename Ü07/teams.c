#include <stdio.h>
#include <math.h>

int main(){
    struct team {
        int nummer;
        unsigned int punkte[13];
    };
    struct team teams[11];
    int gesamtpunkte[11] = {0,0,0,0,0,0,0,0,0,0};
    int index = 0;

    //Eingabe
    for(int a=0; a<10; a++){
        scanf("%d", &teams[a].nummer);
        for(int b=0; b<12;++b){
            scanf("%u", &teams[a].punkte[b]);
        }
    }

    //Ausgabe Teams
    for(int c=0; c<10; ++c){
        printf("%d", teams[c].nummer);
        for(int d=0; d<12; ++d){
            printf(" %u", teams[c].punkte[d]);
        }
        printf("\n");
    }

    //Ausgabe Gruppe 3
    printf("Alle Teams der Gruppe 3:");
    for(int e=0; e<10; ++e){
        if(teams[e].nummer >= 300 && teams[e].nummer < 400){
            printf(" %d", teams[e].nummer);
        }
    }
    printf("\n");

    //Ausgabe höchste Punktzahl
    for(int f=0; f<10; ++f){
        for(int g=0; g<12;++g){
            gesamtpunkte[f] += teams[f].punkte[g];
        }
    }

    for(int g=0; g<11; g++){
        if(gesamtpunkte[index+1] > gesamtpunkte[index]){
            index +=1;
        }
    }
    printf("Team mit der hoechsten Gesamtpunktzahl: %d", teams[index].nummer);

    

}