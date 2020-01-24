int retrieveContent(char* output, char* url, int debug, char* debugIndicator, char* errorIndicator){
    if (debug == 1){//debug reading a file
	    printf("%s reading from file: \"%s\"\n", debugIndicator, url);
	}

    //create file pointer
    FILE* fp;
    char str[1000];
    fp = fopen(url, "r");

    //error if file doest exist
    if (fp == NULL){
        printf("%s it seems like the file you are trying to run (%s) doesnt exist", errorIndicator, url);
        printf("\033[0m");//stop ansi colors
        exit(0);
    }

    while (fgets(str, 1000, fp) != NULL){
        printf("%s reading line: %s", debugIndicator, str);
    }

    fclose(fp);
    return strlen(output);//this is just to make the compiler happy
}