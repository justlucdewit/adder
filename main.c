#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//project information
#define EXTENSION ".add"
#define VERSION "adder 0.0.0.1"
#define NAME "adder"

char* debugIndicator = "[Debug]";
char* errorIndicator = "[Error]";

//boolean to for debugging mode
int debug = 1;

int main(int argc, char** argv)
{
	printf("\n");
	//error if no arguments were supplied
	if (argc < 2){
		printf("%s it seems like you didnt supply enough arguments, try \"%s help\"", errorIndicator, NAME);
		return 1;
	}

	//run command
	if (strcmp(argv[1], "run") == 0){
		if (argc < 3){
			printf("%s it seems like you tried running a file but didnt give a filename, try \"%s run path/to/file\"", errorIndicator, NAME);
			return 1;
		}
		
		//retrieving file content
		char * fileName = malloc(strlen(argv[2]) + strlen(EXTENSION) + 1);
		strcpy(fileName, argv[2]);
		strcat(fileName, EXTENSION);

		if (debug == 1){
			printf("%s \"reading from file %s\"", debugIndicator, fileName);
		}
		return 0;
	}

	//help command
	else if (strcmp(argv[1], "help") == 0){
		printf("%s help\t\tdisplays all the available commands for adder\n", NAME);
		printf("%s version\t\tdisplays the currently installed version of adder\n", NAME);
		printf("%s run [filename]\truns the program giving as argument\n", NAME);
		return 0;
	}

	//version command
	else if (strcmp(argv[1], "version") == 0){
		printf(VERSION);
		return 0;
	}

	//invallid command
	else{
		printf("%s it seems like %s is a invalid command, try \"%s help\"", argv[1], errorIndicator, NAME);
		return 0;
	}
}
