#ifndef guard
#define guard
#include <stdio.h>
#include <stdarg.h>
#include <string.h>

void printcolor(char *formatString, char *color, ...)
{
    va_list args;
    va_start(args, color);

    if (strcmp(color, "red") == 0)
    {
        printf("\033[31m[Error]");
    }

    else if (strcmp(color, "green") == 0)
    {
        printf("\033[32m[Debug]");
    }

    vprintf(formatString, args);
    va_end(args);
    fflush(stdout);
    printf("\033[0m");
}

#endif