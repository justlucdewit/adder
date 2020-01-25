char *retrieveContent(char *url, int debug, char *debugIndicator, char *errorIndicator)
{
    char *output = malloc(1);
    *output = '\0';
    if (debug == 1)
    { //debug reading a file
        printf("%s reading from file: \"%s\"\n", debugIndicator, url);
    }

    //create file pointer
    FILE *fp = fopen(url, "r");

    //error if file doest exist
    if (fp == NULL)
    {
        printf("%s it seems like the file you are trying to run (%s) doesnt exist", errorIndicator, url);
        printf("\033[0m"); //stop ansi colors
        exit(0);
    }

    char line[255];
    while (!feof(fp))
    {
        fgets(line, 150, fp);                                        //get current line
        output = realloc(output, strlen(output) + strlen(line) + 1); //grow output buffer
        strcat(output, line);                                        //append line to output
        //printf("%s", line);
    }

    fclose(fp);

    return output;
}