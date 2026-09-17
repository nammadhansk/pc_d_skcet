@taskkill /f /im lexer.exe >nul 2>&1
flex lexer.l
gcc lex.yy.c -o lexer.exe
lexer.exe
