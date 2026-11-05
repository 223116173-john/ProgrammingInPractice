# Week 12 — Recorded test output

The following results were captured by running the compiled C programs with scripted input under GCC `-std=c99 -Wall -Wextra -pedantic -Werror`. They are **automated terminal test evidence**, not screenshots or claims of manual demonstration.

## Run 1: five structure types and binary save retained

```text
Employees: 3 / 100
Suppliers: 3
Assets: 3 | Total value: N$12000.00
Budgets: 3
Projects: 3
Enter your choice: Saved 3 employee(s) to data/employees.dat
```

## Run 2: update same employee twice, search missing ID, inspect original array

```text
Enter your choice: Loaded 3 employee(s) from binary file.
Enter your choice: Employee ID to update: New salary (N$): Updated: 1002 | Employee1002 | N$19000.00
Enter your choice: Employee ID to update: New salary (N$): Updated: 1002 | Employee1002 | N$20000.00
Enter your choice: Employee ID to update: Employee not found.
Enter your choice: Employee ID to search: Employee not found.
Employees: 3 / 100
```

## Run 3: swap by value/address, array statistics and in-place raises

```text
Enter your choice: Pointer warm-up: value=25, address=0x7fffcfc8da8c, *p=25
Before wrong swap: 15000.00, 21000.00
After wrong swap: 15000.00, 21000.00 (unchanged)
After correct swap: 21000.00, 15000.00
Highest: N$21000.75 | Average: N$18167.08
After 10 percent raise (the original array changed):
calloc example (three zero counters): 0 0 0
Enter your choice: Raise percent: Applied 10.00% raise to 3 employee(s).
Enter your choice: Employee payroll: 3 employees | Monthly total N$66066.00 | Highest N$22033.00
```

## Extra: standalone pointer lab12.c

```text
After wrong swap: 15000.00, 21000.00 (unchanged)
After correct swap: 21000.00, 15000.00
Updated by pointer: Simon, N$19000.00
Updated twice: Simon, N$20000.00
Employee ID 9999 not found.
```

Note: Menu prompts are omitted from these excerpts; they are present in the full program runs. Runtime data files were written in temporary test directories rather than committed to Git.
