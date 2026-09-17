@taskkill /f /im parser.exe >nul 2>&1
@set M4=C:\PROGRA~2\GnuWin32\bin\m4.exe
@set BISON_PKGDATADIR=C:\PROGRA~2\GnuWin32\share\bison
flex parser.l
bison -dy parser.y
gcc lex.yy.c y.tab.c -o parser.exe
parser.exe
