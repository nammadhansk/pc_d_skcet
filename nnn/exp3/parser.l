%{
#include "y.tab.h"
%}

%%
[a-zA-Z][a-zA-Z0-9_]* { return ID; }
"+" { return '+'; }
"*" { return '*'; }
"(" { return '('; }
")" { return ')'; }
"\n" { return '\n'; }
[ \t] { }
. { return yytext[0]; }
%%

int yywrap()
{
 return 1;
}
