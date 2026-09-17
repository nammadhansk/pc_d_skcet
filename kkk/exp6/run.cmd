@taskkill /f /im shiftreduce.exe >nul 2>&1
gcc shiftreduce.c -o shiftreduce.exe
shiftreduce.exe
