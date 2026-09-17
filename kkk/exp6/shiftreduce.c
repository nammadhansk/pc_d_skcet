#include <stdio.h>
#include <string.h>

char stack[100];
char input[100];
int top = -1;
int ip = 0;

void shift()
{
    stack[++top] = input[ip++];
    stack[top + 1] = '\0';
    printf("%-15s %-15s SHIFT\n", stack, &input[ip]);
}

int reduce()
{
    /* Reduce i to E */
    if (top >= 0 && stack[top] == 'i')
    {
        stack[top] = 'E';
        stack[top + 1] = '\0';
        printf("%-15s %-15s REDUCE E->id\n",
               stack, &input[ip]);
        return 1;
    }
    /* Reduce E+E to E */
    if (top >= 2 &&
        stack[top - 2] == 'E' &&
        stack[top - 1] == '+' &&
        stack[top] == 'E')
    {
        top -= 2;
        stack[top] = 'E';
        stack[top + 1] = '\0';
        printf("%-15s %-15s REDUCE E->E+E\n",
               stack, &input[ip]);
        return 1;
    }
    /* Reduce E*E to E */
    if (top >= 2 &&
        stack[top - 2] == 'E' &&
        stack[top - 1] == '*' &&
        stack[top] == 'E')
    {
        top -= 2;
        stack[top] = 'E';
        stack[top + 1] = '\0';
        printf("%-15s %-15s REDUCE E->E*E\n",
               stack, &input[ip]);
        return 1;
    }
    return 0;
}

int main()
{
    printf("Grammar:\n");
    printf("E -> E+E\n");
    printf("E -> E*E\n");
    printf("E -> id\n\n");

    printf("Enter the input string: ");
    scanf("%s", input);

    strcat(input, "$");
    stack[++top] = '$';
    stack[top + 1] = '\0';

    printf("\n%-15s %-15s ACTION\n", "STACK", "INPUT");
    printf("---------------------------------------------\n");

    while (input[ip] != '$')
    {
        shift();
        while (reduce())
        {
            /* Continue reducing */
        }
    }
    /* Final reductions */
    while (reduce())
    {
        /* Continue reducing */
    }

    if (top == 1 && stack[0] == '$' && stack[1] == 'E')
    {
        printf("\nInput string is ACCEPTED.\n");
    }
    else
    {
        printf("\nInput string is REJECTED.\n");
    }
    return 0;
}
