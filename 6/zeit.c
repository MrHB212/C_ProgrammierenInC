#include <time.h>
#include <stdio.h>

int main (void) {
    long sekunden = 0;
    scanf("%ld", &sekunden);
    struct tm * ortszeit;
    ortszeit = gmtime(&sekunden);

    int test = gmtime(&sekunden);
    char * tag [7] = {"Sonntag", "Montag", "Dienstag", "Mittwoch", "Donnerstag", "Freitag", "Samstag"};
    char * monate [12] = {"Januar", "Februar", "März", "April", "Mai", "Juni", "Juli", "August", "September", "Oktober", "November", "Dezember"};
    
    int tagM = ortszeit->tm_mday;
    int jahr = ortszeit->tm_year;
    
    printf ("%s, ", tag[ortszeit->tm_wday]); 
    printf("%d. %s %d, ", tagM, monate[ortszeit->tm_mon], 1900+jahr);
    printf ("%02d:%02d", ortszeit->tm_hour, ortszeit->tm_min);

    
    
}