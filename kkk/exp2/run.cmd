@taskkill /f /im calc.exe >nul 2>&1
@set M4=C:\PROGRA~2\GnuWin32\bin\m4.exe
@set BISON_PKGDATADIR=C:\PROGRA~2\GnuWin32\share\bison
flex calc.l
bison -dy calc.y
gcc lex.yy.c y.tab.c -o calc.exe
calc.exe
