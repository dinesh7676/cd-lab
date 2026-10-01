
#include <stdio.h>
#include <string.h>

int main()
{
    char stack[30], input[30], action[30];
    int top = -1, i = 0, len;

    printf("Grammar:\n");
    printf("E -> E+E\n");
    printf("E -> E*E\n");
    printf("E -> id (enter 'i' for id)\n\n");

    printf("Enter input string: ");

    if (scanf("%29s", input) != 1)
        return 1;

    len = strlen(input);

    printf("\nStack\t\tInput\t\tAction\n");
    printf("-----------------------------------------\n");

    for (i = 0; i < len; i++)
    {
        top++;
        stack[top] = input[i];
        stack[top + 1] = '\0';

        printf("$%s\t\t%s$\t\tShift %c\n",
               stack, input + i + 1, input[i]);

        /* Reduce E -> id */
        if (stack[top] == 'i')
        {
            stack[top] = 'E';

            printf("$%s\t\t%s$\t\tReduce E -> id\n",
                   stack, input + i + 1);
        }

        /* Reduce E -> E+E or E -> E*E */
        if (top >= 2 &&
            stack[top] == 'E' &&
            stack[top - 2] == 'E')
        {
            if (stack[top - 1] == '+')
            {
                top -= 2;

                stack[top] = 'E';
                stack[top + 1] = '\0';

                printf("$%s\t\t%s$\t\tReduce E -> E+E\n",
                       stack, input + i + 1);
            }
            else if (stack[top - 1] == '*')
            {
                top -= 2;

                stack[top] = 'E';
                stack[top + 1] = '\0';

                printf("$%s\t\t%s$\t\tReduce E -> E*E\n",
                       stack, input + i + 1);
            }
        }
    }

    /* Check whether only E remains on stack */
    if (top == 0 && stack[0] == 'E')
    {
        printf("\nSuccess: String is Parsed / Accepted!\n");
    }
    else
    {
        printf("\nFailure: String Rejected.\n");
    }

    return 0;
}
