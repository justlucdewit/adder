#include <ctype.h>

#include "getTokenType.h"
#include "helpers.h"

/*
    adder's lexer function
    this function is used to take a adder script in the form of
    a string, and turn it into a array of tokens, so a ASP can
    be build out of it
*/

void lexicalanalyzer(char *script)
{
    printf("\n"); //make some space for printing

    //loop trough every character in the script
    int scriptlen = strlen(script);
    for (int i = 0; i < scriptlen; i++)
    {
        //create empty token
        char currchar = script[i];
        struct token currentToken;

        //test if its an integer
        if (isInt(currchar))
        {
            currentToken.type = Integer;
        }

        //test if its an operator
        else if (isOpp(currchar))
        {
            currentToken.type = Operator;
        }

        //else idk what it is
        else
        {
            currentToken.type = Unknown;
        }

        //set value of the token
        char stringToken[2] = {currchar, '\0'};
        currentToken.value = stringToken;

        //print out the token
        char *tokentypeString = getTokenType(currentToken.type);
        printf("token[type: %s, value: %s]\n", tokentypeString, currentToken.value);
    }
}