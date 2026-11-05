# Week 11 — Recorded test output

The following results were captured by running the compiled C programs with scripted input under GCC `-std=c99 -Wall -Wextra -pedantic -Werror`. They are **automated terminal test evidence**, not screenshots or claims of manual demonstration.

## Run 1: three records of each of five structure types, reports, save binary/text

```text
Enter your choice: Employee ID: Name: Department: Monthly salary (N$): Employee added successfully.
Enter your choice: Employee ID: Name: Department: Monthly salary (N$): Employee added successfully.
Enter your choice: Employee ID: Name: Department: Monthly salary (N$): Employee added successfully.
Enter your choice: Supplier ID: Name: Email: Phone: Town: Supplier added.
Enter your choice: Supplier ID: Name: Email: Phone: Town: Supplier added.
Enter your choice: Supplier ID: Name: Email: Phone: Town: Supplier added.
Day:   Month:   Year: Asset added.
Day:   Month:   Year: Asset added.
Day:   Month:   Year: Asset added.
Enter your choice: Department: Allocated (N$): Spent (N$): Department budget added.
Enter your choice: Department: Allocated (N$): Spent (N$): Department budget added.
Enter your choice: Department: Allocated (N$): Spent (N$): Department budget added.
Day:   Month:   Year: Project added.
Day:   Month:   Year: Project added.
Day:   Month:   Year: Project added.
Employees: 3 / 100
Suppliers: 3
Assets: 3 | Total value: N$12000.00
Budgets: 3
Projects: 3
Enter your choice: Employee payroll: 3 employees | Monthly total N$60060.00 | Highest N$20030.00
Enter your choice: Municipal budget: 3 departments | Allocated N$30000.00 | Spent N$6000.00 | Balance N$24000.00
Enter your choice: Saved 3 employee(s) to data/employees.dat
Enter your choice: Saved 3 employee(s) to data/employees.txt
```

## Run 2: re-open application, load binary and text files, display restored records

```text
Enter your choice: Loaded 3 employee(s) from binary file.
Employees: 3 / 100
Employees: 3 / 100
Enter your choice: Loaded 3 employee(s) from text file.
```

## Run 3: missing file is handled and empty employee list stays usable

```text
Enter your choice: data/employees.dat: No such file or directory
Enter your choice: data/employees.txt: No such file or directory
Enter your choice: No employees registered.
```

Note: Menu prompts are omitted from these excerpts; they are present in the full program runs. Runtime data files were written in temporary test directories rather than committed to Git.
