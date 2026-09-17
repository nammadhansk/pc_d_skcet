#include <stdio.h>
#include <string.h>

char stack[100];
int top = -1;

void push(char c)
{
    stack[++top] = c;
}

char pop()
{
    return stack[top--];
}

void printStack()
{
    int i;
    for (i = 0; i <= top; i++)
        printf("%c", stack[i]);
}

int main()
{
    char input[100];
    int ip = 0;
    char X;

    printf("Grammar:\n");
    printf("E -> TR\n");
    printf("R -> +TR | e\n");
    printf("T -> FS\n");
    printf("S -> *FS | e\n");
    printf("F -> (E) | i\n\n");

    printf("Enter the input string: ");
    scanf("%s", input);

    strcat(input, "$");
    push('$');
    push('E');

    printf("\n%-15s %-15s Action\n", "Stack", "Input");
    printf("---------------------------------------------\n");

    while (top >= 0)
    {
        X = stack[top];

        /* Print current stack and input */
        printf("%-15s %-15s ", "", "");
        printf("\r");
        printStack();
        printf("%*s", 15 - top - 1, "");
        printf("%-15s ", &input[ip]);

        if (X == '$' && input[ip] == '$')
        {
            printf("Accept\n");
            printf("\nInput string is ACCEPTED.\n");
            break;
        }
        /* Matching terminal */
        if (X == input[ip])
        {
            pop();
            ip++;
            printf("Match %c\n", X);
        }
        /* E -> TR */
        else if (X == 'E')
        {
            pop();
            if (input[ip] == 'i' || input[ip] == '(')
            {
                push('R');
                push('T');
                printf("E -> TR\n");
            }
            else
            {
                printf("Error\n");
                printf("\nInput string is REJECTED.\n");
                break;
            }
        }
        /* R -> +TR or e */
        else if (X == 'R')
        {
            pop();
            if (input[ip] == '+')
            {
                push('R');
                push('T');
                push('+');
                printf("R -> +TR\n");
            }
            else if (input[ip] == ')' || input[ip] == '$')
            {
                printf("R -> e\n");
            }
            else
            {
                printf("Error\n");
                printf("\nInput string is REJECTED.\n");
                break;
            }
        }
        /* T -> FS */
        else if (X == 'T')
        {
            pop();
            if (input[ip] == 'i' || input[ip] == '(')
            {
                push('S');
                push('F');
                printf("T -> FS\n");
            }
            else
            {
                printf("Error\n");
                printf("\nInput string is REJECTED.\n");
                break;
            }
        }
        /* S -> *FS or e */
        else if (X == 'S')
        {
            pop();
            if (input[ip] == '*')
            {
                push('S');
                push('F');
                push('*');
                printf("S -> *FS\n");
            }
            else if (input[ip] == '+' ||
                     input[ip] == ')' ||
                     input[ip] == '$')
            {
                printf("S -> e\n");
            }
            else
            {
                printf("Error\n");
                printf("\nInput string is REJECTED.\n");
                break;
            }
        }
        /* F -> i or (E) */
        else if (X == 'F')
        {
            pop();
            if (input[ip] == 'i')
            {
                push('i');
                printf("F -> i\n");
            }
            else if (input[ip] == '(')
            {
                push(')');
                push('E');
                push('(');
                printf("F -> (E)\n");
            }
            else
            {
                printf("Error\n");
                printf("\nInput string is REJECTED.\n");
                break;
            }
        }
        else
        {
            printf("Error\n");
            printf("\nInput string is REJECTED.\n");
            break;
        }
    }
    return 0;
}
