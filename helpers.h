#ifndef guard
#define guard
#include <stdio.h>
#include <stdarg.h>
#include <string.h>

/*
    printcolor() is a helper function that is able to
    do printf() but with concatenated ANSI codes to generate
    a color
*/

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

int arrayHasChar(char *arr, char character)
{
    int arrlen = sizeof(arr) / sizeof(arr[0]);
    for (int i = 0; i <= arrlen; i++)
    {
        if (arr[i] == character)
        {
            return 1;
        }
    }
    return 0;
}

int isOpp(char character)
{
    if (arrayHasChar("+-*/%", character))
        return 1;
    return 0;
}

int isInt(char character)
{
    if (arrayHasChar("1234567890", character))
        return 1;
    return 0;
}

#endif