#include "command.h"
#include "globals.h"
#include <stdio.h>

int main(void)
{
    char command_char;
    int line_no;
    char text[LINE_LENGTH];

    next_command(&command_char, &line_no, text);

    printf("Kommando: '%c', %i, <%s>\n", command_char, line_no, text);
    return 0;
}