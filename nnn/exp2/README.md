# Exp 2: Implementation of a Calculator using YACC Tool

## Commands to Execute

### Option 1: Using the CMD script
```cmd
run.cmd
```

### Option 2: Step-by-Step Commands
```cmd
flex calc.l
bison -dy calc.y
gcc lex.yy.c y.tab.c -o calc.exe
calc.exe
```

## Input to Enter
When prompted with `Enter an expression: `, enter:
```text
2+3*4
```

## Expected Output
```text
Result = 14
```
