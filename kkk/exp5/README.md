# Exp 5: Implementation of Predictive Parser in C

## Commands to Execute

### Option 1: Using the CMD script
```cmd
run.cmd
```

### Option 2: Step-by-Step Commands
```cmd
gcc predictive.c -o predictive.exe
predictive.exe
```

## Input to Enter

### Valid Input Example
When prompted with `Enter the input string: `, enter:
```text
i+i*i
```
**Expected Output:**
Stack trace ending with:
```text
Input string is ACCEPTED.
```

### Invalid Input Example
```text
i*i+
```
**Expected Output:**
```text
Input string is REJECTED.
```
