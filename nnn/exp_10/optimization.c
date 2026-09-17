#include <stdio.h>
#include <string.h>

struct code
{
    char lhs[10], op1[10], op2[10], op[5];
} c[20];

int main()
{
    int n, i, j;
    int flag[20] = {0};

    printf("Enter number of expressions: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++)
    {
        printf("Enter expression %d (lhs op1 operator op2): ",
               i + 1);

        scanf("%9s %9s %4s %9s",
              c[i].lhs, c[i].op1, c[i].op, c[i].op2);
    }

    printf("\n--- Optimized Code ---\n");

    for (i = 0; i < n; i++)
    {
        if (flag[i] == 0)
        {
            printf("%s = %s %s %s\n",
                   c[i].lhs, c[i].op1, c[i].op, c[i].op2);

            for (j = i + 1; j < n; j++)
            {
                if (strcmp(c[i].op1, c[j].op1) == 0 &&
                    strcmp(c[i].op2, c[j].op2) == 0 &&
                    strcmp(c[i].op, c[j].op) == 0)
                {
                    printf("%s = %s\n",
                           c[j].lhs, c[i].lhs);

                    flag[j] = 1;
                }
            }
        }
    }

    return 0;
}