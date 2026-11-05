# PAP521S — Week 11 — Structures

This folder is for the **Week 11 laboratory** in the **Week 11 & 12: Structures & Pointers in C** PDF (section 11.11, pages 10–12).

This is a standalone, runnable continuation designed from the shared MFMS code and lecturer notes. It is **not an exact copy** of the student’s existing Week 9/10 files. Review and run it before submitting.

## Run in VS Code PowerShell (inside this folder)

```powershell
gcc -std=c99 -Wall -Wextra -pedantic main.c records.c utilities.c -o mfms.exe
.\mfms.exe
```

Do **not** compile `lab12.c` or `lab13.c` together with `main.c`: each has its own `main()`.

## Features

- Five record types defined in `records.h`: `Employee`, `Supplier`, `Asset`, `Budget`, `Project`.
- Nested `Date` structures for asset acquisition and project start/end dates.
- Add and list each record type, payroll and departmental budget reports.
- Employee binary save/load with `fwrite()` / `fread()` at `data/employees.dat`.
- Employee text save/load with `fprintf()` / `sscanf()` at `data/employees.txt`, preserving the Week 10 file-handling idea.
- Simple input validation, duplicate ID protection and explicit error messages.

**Week 11:** To demonstrate binary persistence, add a few employees (1), save (11), exit (0), relaunch, load (12), view (2).

## Data files and portability

Keep VS Code's working directory set to this project folder when running the executable. `data/.gitkeep` preserves the data directory in Git. Binary `.dat` files store native C structure layouts and are **not** portable interchange formats. Text format is `id|name|department|salary`. It differs from the older Week 10 `id|name|salary` format because Week 11 adds a department field.

This repository intentionally ignores runtime employee data files and compiled executables. Do not add personal or real municipal information to public GitHub.

## Testing and submission

See `TEST_EVIDENCE.md` for output captured by automated test runs, plus `TEST_SCENARIOS.md` for steps to demonstrate manually in VS Code. Check the results against your own GCC environment before submission. Git commit history becomes visible after you commit and push this project.
