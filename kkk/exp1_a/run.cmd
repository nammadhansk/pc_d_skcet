@taskkill /f /im lexer.exe >nul 2>&1
gcc lexer.c -o lexer.exe
lexer.exe
