/*
	code is written by luc de wit
	project started on tueseday 23 december 2020
	if you are going to work on this, i wish you the best of luck
	and hope you can keep up your mentality, sorry for the trouble :(
	version works like this:
	mainversion.mainupdate.minorupdate:part
*/

#include <stdio.h>
#include <stdint.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>

//own headers
#include "retrieveContent.h"
#include "lexicalanalyzer.h"
#include "getTokenType.h"
#include "helpers.h"

//project information
#define EXTENSION ".add"
#define VERSION "adder 1.1.1:4"
#define NAME "adder"

//! ansi colors dont work in cmd :(
int main(int argc, char **argv)
{
	//error if no arguments were supplied
	if (argc < 2)
	{
		printcolor("it seems like you didnt supply enough arguments, try \"%s help\"", "red", NAME);
		printf("\n");
		return 0;
	}

	//run command
	if (strcmp(argv[1], "run") == 0)
	{
		//check if a file name has been given
		if (argc < 3)
		{
			printcolor("it seems like you tried running a file but didnt give a filename, try \"%s run path/to/file\"", "red", NAME);
			printf("\n");
			printf("\033[0m"); //stop ansi colors
			return 0;
		}

		//concatinate and store the file name with extension
		char *fileName = malloc(strlen(argv[2]) + strlen(EXTENSION) + 1);
		strcpy(fileName, argv[2]);
		strcat(fileName, EXTENSION);

		//extract content from file
		char *filecontent = retrieveContent(fileName);

		//tokenfy file content
		printcolor("tokenizing file content\n", "green");
		lexicalanalyzer(filecontent);

		printf("\n");
		printf("\033[0m"); //stop ansi colors
		return 0;
	}

	//help command
	else if (strcmp(argv[1], "help") == 0)
	{
		printf("%s help\t\tdisplays all the available commands for adder\n", NAME);
		printf("%s version\t\tdisplays the currently installed version of adder\n", NAME);
		printf("%s run [filename]\truns the program giving as argument\n", NAME);
		printf("\033[0m"); //stop ansi colors
		return 0;
	}

	//version command
	else if (strcmp(argv[1], "version") == 0)
	{
		printf(VERSION);
		printf("\n");
		return 0;
	}

	//invallid command
	else
	{
		printcolor("it seems like %s is a invalid command, try \"%s help\"", "red", argv[1], NAME);
		printf("\n");
		return 0;
	}
}
