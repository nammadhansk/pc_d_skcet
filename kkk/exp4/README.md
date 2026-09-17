# Exp 4: Implementation of Symbol Table in C

## Commands to Execute

### Option 1: Using the CMD script
```cmd
run.cmd
```

### Option 2: Step-by-Step Commands
```cmd
gcc symbol.c -o symbol.exe
symbol.exe
```

## Input to Enter
When prompted with `Enter the number of declarations: `, enter `2` then the declarations:
```text
2
int a,b
float c,d
```

## Expected Output
```text
---------------- SYMBOL TABLE ----------------
Symbol       Address      Type         Size     Offset  
-------------------------------------------------------
a            1000         int          4        0       
b            1004         int          4        4       
c            1008         float        4        8       
d            1012         float        4        12      
```
