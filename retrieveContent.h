#define debug 1
#include "printcolor.h"

char *retrieveContent(char *url)
{
    char *output = malloc(1);
    *output = '\0';
    if (debug == 1)
    { //debug reading a file
        printcolor("reading from file: \"%s\"\n", "green", url);
    }

    //create file pointer
    FILE *fp = fopen(url, "r");

    //error if file doest exist
    if (fp == NULL)
    {
        printcolor("it seems like the file you are trying to run (%s) doesnt exist", "red", url);
        exit(0);
    }

    char line[255];
    while (!feof(fp))
    {
        fgets(line, 150, fp);                                        //get current line
        output = realloc(output, strlen(output) + strlen(line) + 1); //grow output buffer
        strcat(output, line);                                        //append line to output
    }

    fclose(fp);

    return output;
}