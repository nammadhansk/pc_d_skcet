@taskkill /f /im symbol.exe >nul 2>&1
gcc symbol.c -o symbol.exe
symbol.exe
