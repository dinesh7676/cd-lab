#include <stdio.h>
#include <string.h>

char str[100];
int i = 0;

void S()
{
    if (str[i] == 'a')
    {
        i++;
        S();

        if (str[i] == 'b')
            i++;
        else
        {
            printf("Invalid String\n");
            return;
        }
    }
}

int main()
{
    printf("Enter the string: ");
    scanf("%s", str);

    S();

    if (str[i] == '\0')
        printf("Valid String\n");
    else
        printf("Invalid String\n");

    return 0;
}
