#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//own headers
#include "retrieveContent.h"

#define ANSIRED "\033[91m"
#define ANSIGREEN "\033[92m"
#define ANSISTOP "\033[0m"

//version works like this:
//mainversion.mainupdate.minorupdate:part

//project information
#define EXTENSION ".add"
#define VERSION "adder 1.1.1:2"
#define NAME "adder"

char* debugIndicator = "\033[92m[Debug]";
char* errorIndicator = "\033[91m[Error]";

//boolean to for debugging mode
int debug = 1;

int main(int argc, char** argv)
{
	//error if no arguments were supplied
	if (argc < 2){
		printf("%s it seems like you didnt supply enough arguments, try \"%s help\"", errorIndicator, NAME);
		printf("\n");
		printf("\033[0m");//stop ansi colors
		return 1;
	}

	//run command
	if (strcmp(argv[1], "run") == 0){
		if (argc < 3){
			printf("%s it seems like you tried running a file but didnt give a filename, try \"%s run path/to/file\"", errorIndicator, NAME);
			printf("\n");
			printf("\033[0m");//stop ansi colors
			return 1;
		}
		
		//retrieving file content
		char * fileName = malloc(strlen(argv[2]) + strlen(EXTENSION) + 1);
		strcpy(fileName, argv[2]);
		strcat(fileName, EXTENSION);

		if (debug == 1){
			printf("%s reading from file: \"%s\"", debugIndicator, fileName);
		}
		printf("\n");
		printf("\033[0m");//stop ansi colors
		return 0;
	}

	//help command
	else if (strcmp(argv[1], "help") == 0){
		printf("%s help\t\tdisplays all the available commands for adder\n", NAME);
		printf("%s version\t\tdisplays the currently installed version of adder\n", NAME);
		printf("%s run [filename]\truns the program giving as argument\n", NAME);
		printf("\033[0m");//stop ansi colors
		return 0;
	}

	//version command
	else if (strcmp(argv[1], "version") == 0){
		printf(VERSION);
		printf("\n");
		printf("\033[0m");//stop ansi colors
		return 0;
	}

	//invallid command
	else{
		printf("%s it seems like %s is a invalid command, try \"%s help\"", errorIndicator, argv[1], NAME);
		printf("\n");
		printf("\033[0m");//stop ansi colors
		return 0;
	}
}
