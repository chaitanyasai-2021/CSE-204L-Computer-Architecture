// Construct Recursive Descent Parser for the grammar
// G = ({S, L}, {(, ), a, ,}, {S  (L) | a ; L L, S | S}, S) and verify the acceptability of the
// following strings:
// i. (a,(a,a))
// ii. (a,((a,a),(a,a)))

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int i = 0, error = 0;
char input[100];

void S();
void L();

void S()
{
    if (input[i] == '(')
    {
        i++;
        L();
        if (input[i] == ')')
        {
            i++;
        }
        else
        {
            error = 1;
        }
    }
    else if (input[i] == 'a')
    {
        i++;
    }
    else
    {
        error = 1;
    }
}

void L()
{
    S();
    if (input[i] == ',')
    {
        i++;
        S();
    }
    else
    {
        error = 1;
    }
}

int main()
{
    printf("Enter the string: ");
    scanf("%s", input);
    S();
    if (strlen(input) == i && error == 0)
    {
        printf("String is accepted\n");
    }
    else
    {
        printf("String is not accepted\n");
    }
return 0;
}