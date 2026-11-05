#include "records.h"
#include "utilities.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


/* Week 11-12: arrays of structures and counters. */
static Employee employees[MAX_RECORDS];
static size_t employeeCount = 0;

static Supplier suppliers[MAX_RECORDS];
static Asset assets[MAX_RECORDS];
static Budget budgets[MAX_RECORDS];
static Project projects[MAX_RECORDS];
static size_t supplierCount = 0, assetCount = 0, budgetCount = 0, projectCount = 0;

size_t getEmployeeCount(void) { return employeeCount; }
Employee *getEmployeeArray(void) { return employees; }


int initializeRecords(void) { return 1; }
void freeRecords(void) { /* All arrays are statically allocated in Weeks 11-12. */ }

static int employeeIdExists(int id)
{
    size_t i;
    for (i = 0; i < employeeCount; i++) if (employees[i].id == id) return 1;
    return 0;
}

void addEmployee(void)
{
    Employee e = {0};

    if (employeeCount == MAX_RECORDS) { puts("Employee register full."); return; }

    if (!promptInt("Employee ID: ", &e.id) || e.id <= 0) {
        puts("ID must be positive."); return;
    }
    if (employeeIdExists(e.id)) { puts("That employee ID already exists."); return; }
    if (!promptText("Name: ", e.name, sizeof e.name) ||
        !promptText("Department: ", e.department, sizeof e.department) ||
        !promptDouble("Monthly salary (N$): ", &e.salary)) return;

    employees[employeeCount++] = e;
    puts("Employee added successfully.");
}

void displayEmployees(void)
{
    size_t i;
    if (employeeCount == 0) { puts("No employees registered."); return; }
    printf("\n%-7s %-29s %-19s %12s\n", "ID", "Name", "Department", "Salary N$");
    for (i = 0; i < employeeCount; i++) {
        printf("%-7d %-29s %-19s %12.2f\n", employees[i].id,
               employees[i].name, employees[i].department, employees[i].salary);
    }
    printf("Employees: %zu / %d\n", employeeCount, MAX_RECORDS);

}

void addSupplier(void)
{
    Supplier s = {0}; size_t i;
    if (supplierCount == MAX_RECORDS) { puts("Supplier register full."); return; }
    if (!promptInt("Supplier ID: ", &s.id) || s.id <= 0) { puts("Invalid ID."); return; }
    for (i=0;i<supplierCount;i++) if (suppliers[i].id == s.id) { puts("Duplicate ID."); return; }
    if (!promptText("Name: ", s.name, sizeof s.name) ||
        !promptText("Email: ", s.email, sizeof s.email) ||
        !promptText("Phone: ", s.phone, sizeof s.phone) ||
        !promptText("Town: ", s.town, sizeof s.town)) return;
    suppliers[supplierCount++] = s; puts("Supplier added.");
}

void displaySuppliers(void)
{
    size_t i;
    if (!supplierCount) { puts("No suppliers registered."); return; }
    puts("\nID     Name                 Email                   Phone          Town");
    for(i=0;i<supplierCount;i++)
        printf("%-6d %-20s %-23s %-14s %s\n", suppliers[i].id, suppliers[i].name,
               suppliers[i].email, suppliers[i].phone, suppliers[i].town);
    printf("Suppliers: %zu\n", supplierCount);
}

void addAsset(void)
{
    Asset a = {0}; size_t i;
    if (assetCount == MAX_RECORDS) { puts("Asset register full."); return; }
    if (!promptInt("Asset ID: ", &a.id) || a.id <= 0) { puts("Invalid ID."); return; }
    for (i=0;i<assetCount;i++) if (assets[i].id == a.id) { puts("Duplicate ID."); return; }
    if (!promptText("Description: ", a.description, sizeof a.description) ||
        !promptDouble("Value (N$): ", &a.value) ||
        !promptDate("Acquisition date:", &a.acquired.day,
                    &a.acquired.month, &a.acquired.year)) return;
    assets[assetCount++] = a; puts("Asset added.");
}

void displayAssets(void)
{
    size_t i; double total = 0;
    if (!assetCount) { puts("No assets registered."); return; }
    puts("\nID     Description                           Value N$       Acquired");
    for (i=0;i<assetCount;i++) {
        printf("%-6d %-37s %12.2f    %02d/%02d/%04d\n", assets[i].id,
               assets[i].description, assets[i].value, assets[i].acquired.day,
               assets[i].acquired.month, assets[i].acquired.year);
        total += assets[i].value;
    }
    printf("Assets: %zu | Total value: N$%.2f\n", assetCount, total);
}

void addBudget(void)
{
    Budget b = {0};
    if (budgetCount == MAX_RECORDS) { puts("Budget register full."); return; }
    if (!promptText("Department: ", b.department, sizeof b.department) ||
        !promptDouble("Allocated (N$): ", &b.allocated) ||
        !promptDouble("Spent (N$): ", &b.spent)) return;
    budgets[budgetCount++] = b; puts("Department budget added.");
}

void displayBudgets(void)
{
    size_t i;
    if (!budgetCount) { puts("No budgets registered."); return; }
    puts("\nDepartment            Allocated N$       Spent N$       Balance N$");
    for (i=0;i<budgetCount;i++) {
        double balance = budgets[i].allocated - budgets[i].spent;
        printf("%-20s %14.2f %14.2f %16.2f%s\n", budgets[i].department,
               budgets[i].allocated, budgets[i].spent, balance,
               balance < 0 ? " OVER BUDGET" : "");
    }
    printf("Budgets: %zu\n", budgetCount);
}

void addProject(void)
{
    Project p = {0}; size_t i;
    if (projectCount == MAX_RECORDS) { puts("Project register full."); return; }
    if (!promptInt("Project ID: ", &p.id) || p.id <= 0) { puts("Invalid ID."); return; }
    for (i=0;i<projectCount;i++) if (projects[i].id == p.id) { puts("Duplicate ID."); return; }
    if (!promptText("Title: ", p.title, sizeof p.title) ||
        !promptDouble("Budget (N$): ", &p.budget) ||
        !promptDate("Start date:", &p.startDate.day, &p.startDate.month, &p.startDate.year) ||
        !promptDate("End date:", &p.endDate.day, &p.endDate.month, &p.endDate.year)) return;
    projects[projectCount++] = p; puts("Project added.");
}

void displayProjects(void)
{
    size_t i;
    if (!projectCount) { puts("No projects registered."); return; }
    puts("\nID     Title                                  Budget N$    Start       End");
    for (i=0;i<projectCount;i++) {
        printf("%-6d %-38s %12.2f   %02d/%02d/%04d  %02d/%02d/%04d\n",
               projects[i].id, projects[i].title, projects[i].budget,
               projects[i].startDate.day, projects[i].startDate.month, projects[i].startDate.year,
               projects[i].endDate.day, projects[i].endDate.month, projects[i].endDate.year);
    }
    printf("Projects: %zu\n", projectCount);
}

void payrollReport(void)
{
    size_t i; double total = 0, highest = 0;
    for (i=0;i<employeeCount;i++) {
        total += employees[i].salary;
        if (i == 0 || employees[i].salary > highest) highest = employees[i].salary;
    }
    printf("Employee payroll: %zu employees | Monthly total N$%.2f | Highest N$%.2f\n",
           employeeCount, total, highest);
}

void municipalBudgetReport(void)
{
    size_t i; double allocated=0, spent=0;
    for (i=0;i<budgetCount;i++) {
        allocated += budgets[i].allocated;
        spent += budgets[i].spent;
    }
    printf("Municipal budget: %zu departments | Allocated N$%.2f | Spent N$%.2f | Balance N$%.2f\n",
           budgetCount, allocated, spent, allocated - spent);
}

void saveEmployeesBinary(void)
{
    FILE *fp; size_t count;
    if (!ensureDataDirectory()) return;
    fp = fopen("data/employees.dat", "wb");
    if (fp == NULL) { perror("data/employees.dat"); return; }
    count = fwrite(employees, sizeof *employees, employeeCount, fp);
    if (count != employeeCount) { perror("Cannot write all employee records"); fclose(fp); return; }
    if (fclose(fp) != 0) { perror("Cannot close employee binary file"); return; }
    printf("Saved %zu employee(s) to data/employees.dat\n", count);
}


void loadEmployeesBinary(void)
{
    FILE *fp; Employee incoming[MAX_RECORDS];
    size_t count;
    int extra, failed;
    fp = fopen("data/employees.dat", "rb");
    if (fp == NULL) { perror("data/employees.dat"); return; }
    count = fread(incoming, sizeof incoming[0], MAX_RECORDS, fp);
    failed = ferror(fp);
    extra = fgetc(fp); /* Detect a file with more than MAX_RECORDS records. */
    if (extra != EOF) failed = 1;
    /* Reject a truncated last record rather than losing it silently. */
    if (fseek(fp, 0, SEEK_END) == 0) {
        long bytes = ftell(fp);
        if (bytes < 0 || (unsigned long)bytes % sizeof incoming[0] != 0) failed = 1;
    } else failed = 1;
    if (fclose(fp) != 0) failed = 1;
    if (failed) { puts("Unable to load employee data (or file too large)."); return; }
    memcpy(employees, incoming, count * sizeof incoming[0]);
    employeeCount = count;
    printf("Loaded %zu employee(s) from binary file.\n", count);
}

void saveEmployeesText(void)
{
    FILE *fp; size_t i;
    if (!ensureDataDirectory()) return;
    fp = fopen("data/employees.txt", "w");
    if (fp == NULL) { perror("data/employees.txt"); return; }
    for (i=0;i<employeeCount;i++) {
        if (fprintf(fp, "%d|%s|%s|%.2f\n", employees[i].id,
                    employees[i].name, employees[i].department,
                    employees[i].salary) < 0) {
            perror("Could not save employee text record"); fclose(fp); return;
        }
    }
    if (fclose(fp) != 0) { perror("Could not close employee text file"); return; }
    printf("Saved %zu employee(s) to data/employees.txt\n", employeeCount);
}

void loadEmployeesText(void)
{
    FILE *fp;
    char line[256];
    size_t count = 0;

    Employee loaded[MAX_RECORDS];

    fp = fopen("data/employees.txt", "r");
    if (fp == NULL) { perror("data/employees.txt");

        return; }
    while (fgets(line, sizeof line, fp) != NULL) {
        Employee e = {0}; char tail;
        /* Reject malformed/truncated lines rather than silently losing records. */
        if (!strchr(line, '\n') && !feof(fp)) {
            puts("Text data has an overlong line. Not loaded.");
            fclose(fp);

            return;
        }
        if (sscanf(line, "%d|%29[^|]|%19[^|]|%lf %c",
                   &e.id, e.name, e.department, &e.salary, &tail) != 4 ||
            e.id <= 0 || e.salary < 0 || e.salary != e.salary) {
            puts("Malformed employee text record. Not loaded."); fclose(fp);

            return;
        }

        if (count == MAX_RECORDS) { puts("Too many employee records."); fclose(fp); return; }

        loaded[count++] = e;
    }
    if (ferror(fp)) { puts("Error reading employee text file."); fclose(fp);

        return; }
    if (fclose(fp) != 0) { puts("Error closing text file.");

        return; }

    memcpy(employees, loaded, count * sizeof loaded[0]);
    employeeCount = count;

    printf("Loaded %zu employee(s) from text file.\n", count);
}

void searchEmployeeMenu(void)
{
    int id; size_t i;
    if (!promptInt("Employee ID to search: ", &id)) return;
    for (i=0;i<employeeCount;i++) {
        if (employees[i].id == id) {
            printf("Found: %d | %s | %s | N$%.2f\n", employees[i].id,
                   employees[i].name, employees[i].department, employees[i].salary);
            return;
        }
    }
    puts("Employee not found.");
}


void updateEmployeeSalaryMenu(void) { puts("Available in Week 12."); }
void giveEmployeesRaiseMenu(void) { puts("Available in Week 12."); }
