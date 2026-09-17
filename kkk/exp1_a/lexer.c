#include <stdio.h>
#include <string.h>
#include <ctype.h>

int isKeyword(char str[])
{
    char keywords[32][10] = {
        "auto", "break", "case", "char", "const", "continue",
        "default", "do", "double", "else", "enum", "extern",
        "float", "for", "goto", "if", "int", "long",
        "register", "return", "short", "signed", "sizeof", "static",
        "struct", "switch", "typedef", "union", "unsigned", "void",
        "volatile", "while"
    };
    int i;
    for (i = 0; i < 32; i++)
    {
        if (strcmp(str, keywords[i]) == 0)
            return 1;
    }
    return 0;
}

int main()
{
    char input[1000];
    int i = 0;
    printf("Enter the C program:\n");
    fgets(input, sizeof(input), stdin);
    printf("\nTokens:\n");
    while (input[i] != '\0')
    {
        /* Ignore spaces and newlines */
        if (isspace(input[i]))
        {
            i++;
        }
        /* Identifier or Keyword */
        else if (isalpha(input[i]) || input[i] == '_')
        {
            char word[50];
            int j = 0;
            while (isalnum(input[i]) || input[i] == '_')
            {
                word[j++] = input[i++];
            }
            word[j] = '\0';
            if (isKeyword(word))
                printf("%s -> Keyword\n", word);
            else
                printf("%s -> Identifier\n", word);
        }
        /* Constant */
        else if (isdigit(input[i]))
        {
            char number[50];
            int j = 0;
            while (isdigit(input[i]))
            {
                number[j++] = input[i++];
            }
            number[j] = '\0';
            printf("%s -> Constant\n", number);
        }
        /* Operators */
        else if (input[i] == '+' || input[i] == '-' ||
                 input[i] == '*' || input[i] == '/' ||
                 input[i] == '=' || input[i] == '<' ||
                 input[i] == '>')
        {
            printf("%c -> Operator\n", input[i]);
            i++;
        }
        /* Special Symbols */
        else if (input[i] == '(' || input[i] == ')' ||
                 input[i] == '{' || input[i] == '}' ||
                 input[i] == '[' || input[i] == ']' ||
                 input[i] == ';' || input[i] == ',')
        {
            printf("%c -> Special Symbol\n", input[i]);
            i++;
        }
        /* Unknown character */
        else
        {
            printf("%c -> Unknown Symbol\n", input[i]);
            i++;
        }
    }
    return 0;
}
