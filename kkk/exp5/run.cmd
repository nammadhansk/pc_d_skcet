@taskkill /f /im predictive.exe >nul 2>&1
gcc predictive.c -o predictive.exe
predictive.exe
