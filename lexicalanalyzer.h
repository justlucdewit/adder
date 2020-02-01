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
    struct token *tokensFound = malloc(1);
    int numOfTokens = 0;
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
        currentToken.value = malloc((sizeof currchar) * 2);
        currentToken.value[0] = currchar;
        currentToken.value[1] = '\0';

        //check if can append int or opp
        if (i != 0)
        {
            struct token lastToken = tokens[];
            if (currentToken.type ==)
        }

        //append token to array
        //char *tokentypeString = getTokenType(currentToken.type);
        numOfTokens += 1;
        tokensFound = realloc(tokensFound, (sizeof currentToken) * numOfTokens);
        tokensFound[numOfTokens - 1] = currentToken;
    }

    //loop over token array and print it
    for (int i = 0; i < numOfTokens; i++)
    {
        printf("token[type: %s, value: %s]\n", getTokenType(tokensFound[i].type), tokensFound[i].value);
    }
}