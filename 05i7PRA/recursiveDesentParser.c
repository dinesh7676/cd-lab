
#include <stdio.h>
#include <string.h>

int main()
{
    char input[100], stack[100];
    int pos = 0, top = -1;

    printf("Enter input string (e.g., i or i+i): ");
    scanf("%99s", input);

    int len = strlen(input);

    input[len] = '$';
    input[len + 1] = '\0';

    stack[++top] = '$';
    stack[++top] = 'E';

    printf("\n%-20s | %-20s\n", "Stack", "Input Lookahead");
    printf("-----------------------------------------\n");

    while (top >= 0)
    {
        stack[top + 1] = '\0';

        printf("%-20s | %-20s\n",
               stack, &input[pos]);

        char stack_top = stack[top--];
        char token = input[pos];

        /* Terminal matches input */
        if (stack_top == token)
        {
            if (stack_top != '$')
                pos++;
        }

        /* E -> TX */
        else if (stack_top == 'E' && token == 'i')
        {
            stack[++top] = 'X';
            stack[++top] = 'T';
        }

        /* T -> i */
        else if (stack_top == 'T' && token == 'i')
        {
            stack[++top] = 'i';
        }

        /* X -> +E | ε */
        else if (stack_top == 'X')
        {
            if (token == '+')
            {
                stack[++top] = 'E';
                stack[++top] = '+';
            }
            else if (token != '$')
            {
                printf("\nString Rejected (Invalid choice for X)\n");
                return 0;
            }
        }

        /* Syntax error */
        else
        {
            printf("\nString Rejected (Syntax Error)\n");
            return 0;
        }
    }

    if (input[pos] == '$')
        printf("\nString Accepted\n");
    else
        printf("\nString Rejected (Unparsed extra tokens remaining)\n");

    return 0;
}