
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

const char *input;
char lookahead;

// Forward declarations
void S();
void L();
void Lprime();
void match(char);
void syntaxError(const char *msg);

// Read next non-space character
void nextToken()
{
    while (*input == ' ')
        input++;   // skip whitespace

    lookahead = *input++;
}

// Match expected character
void match(char expected)
{
    if (lookahead == expected)
    {
        printf("Matched: '%c'\n", expected);
        nextToken();
    }
    else
    {
        syntaxError("Unexpected character");
    }
}

// Report syntax error
void syntaxError(const char *msg)
{
    printf("Syntax Error: %s at '%c'\n", msg, lookahead);
    exit(1);
}

/*
    S -> (L) | a
*/
void S()
{
    if (lookahead == '(')
    {
        printf("Entering S -> (L)\n");

        match('(');
        L();
        match(')');

        printf("Exiting S -> (L)\n");
    }
    else if (lookahead == 'a')
    {
        printf("Entering S -> a\n");

        match('a');

        printf("Exiting S -> a\n");
    }
    else
    {
        syntaxError("Expected '(' or 'a'");
    }
}

/*
    L -> S L'
*/
void L()
{
    printf("Entering L -> S L'\n");

    S();
    Lprime();

    printf("Exiting L -> S L'\n");
}

/*
    L' -> , S L' | ε
*/
void Lprime()
{
    if (lookahead == ',')
    {
        printf("Entering L' -> , S L'\n");

        match(',');
        S();
        Lprime();

        printf("Exiting L' -> , S L'\n");
    }
    else
    {
        printf("L' -> ε\n");
    }
}

// Main function
int main()
{
    char expr[100];

    printf("Enter an expression: ");
    fgets(expr, sizeof(expr), stdin);

    input = expr;
    nextToken();

    // Start parsing from S
    S();

    if (lookahead == '\0' || lookahead == '\n')
    {
        printf("Parsing successful.\n");
    }
    else
    {
        syntaxError("Extra input after valid expression");
    }

    return 0;
}
