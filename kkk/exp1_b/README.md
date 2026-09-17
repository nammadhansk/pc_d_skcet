# Exp 1(b): Implementation of Lexical Analyzer using LEX

## Commands to Execute

### Option 1: Using the CMD script
```cmd
run.cmd
```

### Option 2: Step-by-Step Commands
```cmd
flex lexer.l
gcc lex.yy.c -o lexer.exe
lexer.exe
```

## Input to Enter
When prompted with `Enter the input:`, enter:
```text
int sum = a + 25;
```

## Expected Output
```text
int -> Keyword
sum -> Identifier
= -> Operator
a -> Identifier
+ -> Operator
25 -> Number
; -> Special Symbol
```
