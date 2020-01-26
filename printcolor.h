#ifndef guard
#define guard
#include <stdio.h>
#include <stdarg.h>
#include <string.h>

void printcolor(char *formatString, char *color, ...)
{
    va_list args;
    va_start(args, color);

    char *coloredformat = "\033[37m[FEROR]";

    if (strcmp(color, "red") == 0)
    {
        coloredformat = "\033[30m[Error]";
    }

    else if (strcmp(color, "green") == 0)
    {
        coloredformat = "\033[32m[Debug]";
    }

    strcat(coloredformat, formatString);
    strcat(coloredformat, "\033[0m");
    vprintf(formatString, args);
}

#endif