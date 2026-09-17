# Exp 6: Implementation of Shift Reduce Parser in C

## Commands to Execute

### Option 1: Using the CMD script
```cmd
run.cmd
```

### Option 2: Step-by-Step Commands
```cmd
gcc shiftreduce.c -o shiftreduce.exe
shiftreduce.exe
```

## Input to Enter

### Valid Input Example
When prompted with `Enter the input string: `, enter:
```text
i+i*i
```
**Expected Output:**
Shift and Reduce trace table ending with:
```text
Input string is ACCEPTED.
```

### Invalid Input Example
```text
i++i
```
**Expected Output:**
```text
Input string is REJECTED.
```
