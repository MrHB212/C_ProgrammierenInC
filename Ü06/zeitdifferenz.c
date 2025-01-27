#include <stdio.h>
#include <time.h>

int main (void){
    struct tm wach;
    struct tm weihnachtsfest;
    struct tm *testS;

//Wann ist Carla aufgewacht ?
    wach.tm_mday = 1;
    wach.tm_mon = 11;
    wach.tm_year = 120;
    wach.tm_hour = 6;
    wach.tm_min = 22;
    wach.tm_sec = 17;

//Wann ist das Weihnachtsfest ?
    weihnachtsfest.tm_mday = 25;
    weihnachtsfest.tm_mon = 11;
    weihnachtsfest.tm_year = 120;
    weihnachtsfest.tm_hour = 0;
    weihnachtsfest.tm_min = 0;
    weihnachtsfest.tm_sec = 0;

double a = mktime(&wach);
double b = mktime(&weihnachtsfest);
long test = time(NULL);
testS = localtime(&test);


double diff = difftime(b,a);

printf("Sekunden bis Weihnachten: %.2f\n", diff);
printf("Minuten bis Weihnachten: %.2f\n", diff/60);
printf("Stunden bis Weihnachten: %.2f\n", diff/60/60);
printf("Tage bis Weihnachten: %.2f", diff/60/60/24);



    

    
     




}