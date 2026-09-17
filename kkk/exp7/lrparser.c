#include <stdio.h>
#include <string.h>

char action[6][3] = {
    {'s', ' ', ' '}, // State 0
    {' ', 's', 'a'}, // State 1
    {' ', 'r', 'r'}, // State 2
    {' ', 'r', 'r'}, // State 3
    {'s', ' ', ' '}, // State 4
    {' ', 'r', 'r'}  // State 5
};

int actionNum[6][3] = {
    {3, 0, 0},
    {0, 4, 0},
    {0, 2, 2},
    {0, 3, 3},
    {3, 0, 0},
    {0, 1, 1}
};

/* GOTO table: columns E and T */
int gotoTable[6][2] = {
    {1, 2},
    {0, 0},
    {0, 0},
    {0, 0},
    {0, 5},
    {0, 0}
};

char input[100];
int stack[100];
int top = 0;
int ip = 0;

/* Get ACTION table column */
int getColumn(char symbol)
{
    if (symbol == 'i')
        return 0;
    if (symbol == '+')
        return 1;
    if (symbol == '$')
        return 2;
    return -1;
}

/* Convert stack contents into a string */
void getStackString(char str[])
{
    int i;
    str[0] = '\0';
    for (i = 0; i <= top; i++)
    {
        char temp[10];
        sprintf(temp, "%d ", stack[i]);
        strcat(str, temp);
    }
}

int main()
{
    int state;
    int column;
    char act;
    int number;
    char stackStr[200];

    printf("Grammar:\n");
    printf("1. E -> E+T\n");
    printf("2. E -> T\n");
    printf("3. T -> id\n\n");

    printf("Enter the input string: ");
    scanf("%s", input);

    strcat(input, "$");

    /* Initial state */
    stack[0] = 0;

    printf("\n%-20s %-15s %s\n",
           "Stack", "Input", "Action");
    printf("--------------------------------------------------\n");

    while (1)
    {
        state = stack[top];
        column = getColumn(input[ip]);

        if (column == -1)
        {
            getStackString(stackStr);
            printf("%-20s %-15s Error\n",
                   stackStr, &input[ip]);
            printf("\nInvalid symbol in input.\n");
            printf("\nInput string is REJECTED.\n");
            break;
        }

        act = action[state][column];
        number = actionNum[state][column];
        getStackString(stackStr);

        /* SHIFT */
        if (act == 's')
        {
            char actionText[30];
            sprintf(actionText, "Shift %d", number);
            printf("%-20s %-15s %s\n",
                   stackStr,
                   &input[ip],
                   actionText);
            top++;
            stack[top] = number;
            ip++;
        }
        /* REDUCE */
        else if (act == 'r')
        {
            char actionText[40];
            if (number == 1)
            {
                /*
                E -> E + T
                RHS contains 3 symbols
                */
                sprintf(actionText, "Reduce E -> E+T");
                printf("%-20s %-15s %s\n",
                       stackStr,
                       &input[ip],
                       actionText);
                top = top - 3;
                state = stack[top];
                top++;
                stack[top] = gotoTable[state][0];
            }
            else if (number == 2)
            {
                /*
                E -> T
                RHS contains 1 symbol
                */
                sprintf(actionText, "Reduce E -> T");
                printf("%-20s %-15s %s\n",
                       stackStr,
                       &input[ip],
                       actionText);
                top = top - 1;
                state = stack[top];
                top++;
                stack[top] = gotoTable[state][0];
            }
            else if (number == 3)
            {
                /*
                T -> id
                RHS contains 1 symbol
                */
                sprintf(actionText, "Reduce T -> id");
                printf("%-20s %-15s %s\n",
                       stackStr,
                       &input[ip],
                       actionText);
                top = top - 1;
                state = stack[top];
                top++;
                stack[top] = gotoTable[state][1];
            }
        }
        /* ACCEPT */
        else if (act == 'a')
        {
            printf("%-20s %-15s Accept\n",
                   stackStr,
                   &input[ip]);
            printf("\nInput string is ACCEPTED.\n");
            break;
        }
        /* ERROR */
        else
        {
            printf("%-20s %-15s Error\n",
                   stackStr,
                   &input[ip]);
            printf("\nInput string is REJECTED.\n");
            break;
        }
    }
    return 0;
}
