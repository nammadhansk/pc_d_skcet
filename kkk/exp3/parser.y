%{
#include <stdio.h>
int yylex();
int yyerror(char *s);
%}

%token ID

%%
input:
 expr '\n' { printf("Valid Expression\n"); }
 ;

expr:
 expr '+' term
 | term
 ;

term:
 term '*' factor
 | factor
 ;

factor:
 ID
 | '(' expr ')'
 ;

%%

int yyerror(char *s)
{
 printf("Invalid Expression\n");
 return 0;
}

int main()
{
 printf("Enter an expression: ");
 yyparse();
 return 0;
}
