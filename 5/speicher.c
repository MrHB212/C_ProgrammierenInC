#include <stdio.h>
#include <limits.h>

int main (void){
int a = 46;
int b = 89;
double c = 5.3;
double d = 2017.411;
int *p1 = &a;
int *p2 = &b;
double *p3 = &c;
double *p4 = &d;

printf("sizeof(char)      = %lu Byte; ([%d ... %d])\n", sizeof(char), CHAR_MIN, CHAR_MAX);
printf("sizeof(short)     = %lu Byte; ([%d ... %d])\n", sizeof(short), SHRT_MIN, SHRT_MAX);
printf("sizeof(int)       = %lu Byte; ([%d ... %d])\n", sizeof(int), INT_MIN, INT_MAX);
printf("sizeof(long)      = %lu Byte; ([%ld ... %ld])\n", sizeof(long), LONG_MIN, LONG_MAX);
printf("sizeof(long long) = %lu Byte; ([%lld ... %lld])\n", sizeof(long long), LLONG_MIN, LLONG_MAX);
printf("sizeof(float)     = %lu Byte;\n", sizeof(float));
printf("sizeof(double)    = %lu Byte;\n", sizeof(double));

printf("Wert von a: %d, Speicheradresse von a:%p\n", a, p1);
printf("Wert von b: %d, Speicheradresse von b:%p\n", b, p2);
printf("Wert von c: %f, Speicheradresse von c:%p\n", c, p3);
printf("Wert von d: %f, Speicheradresse von d:%p", d, p4);


}