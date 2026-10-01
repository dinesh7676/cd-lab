
#include <stdio.h>
#include <string.h>

int main()
{
    printf("Grammar:\nS -> a\n\n");

    char input[] = "a";
    char input_buf[10];

    sprintf(input_buf, "%s$", input);

    char stack[20] = "$";
    int s_top = 0;

    int state_stack[20] = {0};
    int st_top = 0;

    int ip = 0;

    printf("Stack\t\tInput\t\tAction\n");
    printf("-----------------------------------------\n");

    while (1)
    {
        int current_state = state_stack[st_top];
        char tok = input_buf[ip];

        /* State 0: Shift a */
        if (current_state == 0)
        {
            if (tok == 'a')
            {
                s_top++;
                stack[s_top] = 'a';
                stack[s_top + 1] = '\0';

                printf("%s\t\t%s\t\tShift a\n",
                       stack, input_buf + ip);

                st_top++;
                state_stack[st_top] = 2;

                ip++;
            }
            else
            {
                printf("\nFailure: String Rejected.\n");
                return 1;
            }
        }

        /* State 2: Reduce S -> a */
        else if (current_state == 2)
        {
            if (tok == '$')
            {
                stack[s_top] = '\0';
                s_top--;

                st_top--;

                printf("%s\t\t%s\t\tReduce S -> a\n",
                       stack, input_buf + ip);

                s_top++;
                stack[s_top] = 'S';
                stack[s_top + 1] = '\0';

                if (state_stack[st_top] == 0)
                {
                    st_top++;
                    state_stack[st_top] = 1;
                }
            }
            else
            {
                printf("\nFailure: String Rejected.\n");
                return 1;
            }
        }

        /* State 1: Accept */
        else if (current_state == 1)
        {
            if (tok == '$')
            {
                printf("%s\t\t%s\t\tAccept\n",
                       stack, input_buf + ip);

                printf("\nSuccess: String is Parsed / Accepted!\n");
                break;
            }
            else
            {
                printf("\nFailure: String Rejected.\n");
                return 1;
            }
        }
    }

    return 0;
}

