# Exp 10: Implementation of Code Optimization in C

## Commands to Execute

### Option 1: Using the CMD script
```cmd
run.cmd
```

### Option 2: Step-by-Step Commands
```cmd
gcc optimization.c -o optimization.exe
optimization.exe
```

## Input to Enter
When prompted with `Enter number of expressions: `, enter the count followed by each expression in `lhs op1 operator op2` format:
```text
3
a b + c
d b + c
e f * g
```

> **Note:** The format `lhs op1 operator op2` corresponds to `lhs = op1 operator op2` (e.g., `a b + c` represents `a = b + c`).

## Expected Output
```text
--- Optimized Code ---
a = b + c
d = a
e = f * g
```
