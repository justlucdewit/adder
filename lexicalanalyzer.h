void lexicalanalyzer(char *script)
{
    printf("\n");
    int scriptlen = strlen(script);
    for (int i = 0; i < scriptlen; i++)
    {
        char currchar = script[i];
        printf("%c\n", currchar);
        //printf("%c\n", script[i]);
    }
}