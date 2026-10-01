
#include <stdio.h>

char input[100];
int pos = 0;

int E();
int Eprime();
int T();

/* T -> i */
int T()
{
    if (input[pos] == 'i')
    {
        pos++;
        return 1;
    }

    return 0;
}

/* E' -> +T E' | *T E' | ε */
int Eprime()
{
    if (input[pos] == '+')
    {
        pos++;

        if (T())
            return Eprime();

        return 0;
    }
    else if (input[pos] == '*')
    {
        pos++;

        if (T())
            return Eprime();

        return 0;
    }

    return 1;   // ε
}

/* E -> T E' */
int E()
{
    if (T())
        return Eprime();

    return 0;
}

int main()
{
    printf("Enter input (use i for id): ");
    scanf("%s", input);

    if (E() && input[pos] == '\0')
        printf("String Accepted\n");
    else
        printf("String Rejected\n");

    return 0;
}
