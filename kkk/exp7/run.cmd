@taskkill /f /im lrparser.exe >nul 2>&1
gcc lrparser.c -o lrparser.exe
lrparser.exe
