
# Municipal Financial Management System

## Week 9 - Multi-File Programming

I organised the Municipal Financial Management System into separate C files instead of keeping everything in one program.

This  system allows a user to register municipal employees, record departmental budgets and view financial summaries.

## Project Files

- main.c - Displays the main menu and controls the program.
- employees.c - Handles employee registration, employee records and payroll calculations.
- employees.h - Contains declarations for employee functions.
- budget.c - Handles departmental budgets and calculates remaining balances.
- budget.h - Contains declarations for budget functions.
- utilities.c - Contains reusable functions for reading user input.
- utilities.h - Contains declarations for the utility functions.
- reports.c - Generates employee payroll and municipal budget reports.
- reports.h - Contains declarations for the reporting functions.

## Compiling the Program

I used GCC to compile the five C source files separately.

    gcc -std=c99 -Wall -Wextra -pedantic -c main.c
    gcc -std=c99 -Wall -Wextra -pedantic -c employees.c
    gcc -std=c99 -Wall -Wextra -pedantic -c budget.c
    gcc -std=c99 -Wall -Wextra -pedantic -c utilities.c
    gcc -std=c99 -Wall -Wextra -pedantic -c reports.c

After compiling, I linked the object files using:

    gcc main.o employees.o budget.o utilities.o reports.o -o mfms

To run the program on Windows:

    .\mfms.exe

## Testing

I tested the menu options, employee registration, employee listing, departmental budgets and financial reports.

The program compiled and linked successfully.

## Conclusion

Dividing the program into separate modules made it easier to organise the different operations. Each source file handles a particular part of the system, while main.c connects them through the menu.
