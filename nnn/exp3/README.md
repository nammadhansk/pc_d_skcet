# Exp 3: Implementation of Parser using LEX and YACC Tool

## Commands to Execute

### Option 1: Using the CMD script
```cmd
run.cmd
```

### Option 2: Step-by-Step Commands
```cmd
flex parser.l
bison -dy parser.y
gcc lex.yy.c y.tab.c -o parser.exe
parser.exe
```

## Input to Enter

### Valid Input Example
When prompted with `Enter an expression: `, enter:
```text
a+b*c
```
**Expected Output:**
```text
Valid Expression
```

### Invalid Input Example
```text
a+*b
```
**Expected Output:**
```text
Invalid Expression
```
