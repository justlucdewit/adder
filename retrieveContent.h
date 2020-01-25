//todo make the function return a string instead of modifying one
//todo make the function actually work
void retrieveContent(char *url, int debug, char *debugIndicator, char *errorIndicator)
{
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

    int n = 0;
    int size = 0;
    while (fscanf(fp, "%*[^\n]\n%n", &n) != EOF)
    {
        size += n;
        printf("%d\n", size);
    }

    //printf("%d\n", size);
    char *output = malloc(size + 2);

    //retrieve file content
    fread(output, 1, size, fp);
    //output[strlen(output)] = '\0';
    printf("%s\n", output);

    fclose(fp);
}