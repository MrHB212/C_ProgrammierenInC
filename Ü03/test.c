#include <stdio.h>
int main ( void )
{
printf (" <%10d >\n", 1234) ;
printf (" <% -10d >\n", 1234) ;
printf (" <%10.5f >\n", 1234.567891011121314) ;
printf (" <%10.3f >\n", 1234.567891011121314) ;
printf (" <%.5f >\n", 12345678910.11121314) ;
printf (" <%14.6e >\n", 1234.567891011121314) ;
return 0;
}