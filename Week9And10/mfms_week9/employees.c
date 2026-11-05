
#include <stdio.h>
#include "employees.h"

#define MAX_EMPLOYEES 50

typedef struct
{
    int id;
    char name[50];
    double salary;
} Employee;

static Employee employees[MAX_EMPLOYEES];
static int totalEmployees = 0;

void addEmployee(void)
{
    if (totalEmployees >= MAX_EMPLOYEES)
    {
        printf("Employee register is full.\n");
        return;
    }

    Employee newEmployee;

    printf("\nEnter employee ID: ");
    if (scanf("%d", &newEmployee.id) != 1)
    {
        printf("Invalid employee ID.\n");
        return;
    }

    for (int i = 0; i < totalEmployees; i++)
    {
        if (employees[i].id == newEmployee.id)
        {
            printf("That employee ID already exists.\n");
            return;
        }
    }

    printf("Enter employee name: ");
    if (scanf(" %49[^\n]", newEmployee.name) != 1)
    {
        printf("Invalid employee name.\n");
        return;
    }

    printf("Enter monthly salary (N$): ");
    if (scanf("%lf", &newEmployee.salary) != 1 ||
        newEmployee.salary < 0)
    {
        printf("Invalid salary amount.\n");
        return;
    }

    employees[totalEmployees] = newEmployee;
    totalEmployees++;

    printf("Employee added successfully.\n");
}

void listEmployees(void)
{
    if (totalEmployees == 0)
    {
        printf("\nNo employees have been added yet.\n");
        return;
    }

    printf("\nMunicipal Employee Register\n");
    printf("-----------------------------\n");

    for (int i = 0; i < totalEmployees; i++)
    {
        printf("\nEmployee ID: %d\n", employees[i].id);
        printf("Name: %s\n", employees[i].name);
        printf("Monthly Salary: N$ %.2f\n",
               employees[i].salary);
    }

    printf("\nTotal employees: %d\n", totalEmployees);
}

double calculatePayrollTotal(void)
{
    double totalPayroll = 0.0;

    for (int i = 0; i < totalEmployees; i++)
    {
        totalPayroll += employees[i].salary;
    }

    return totalPayroll;
}

/* WEEK 10 - SAVE EMPLOYEE RECORDS TO TEXT FILE */

void saveEmployees(void)
{
    if (totalEmployees == 0)
    {
        printf("\nNo employees to save.\n");
        return;
    }

    FILE *fp = fopen("data/employees.txt", "w");

    if (fp == NULL)
    {
        perror("Error opening employees file");
        return;
    }

    for (int i = 0; i < totalEmployees; i++)
    {
        if (fprintf(fp, "%d|%s|%.2f\n",
                    employees[i].id,
                    employees[i].name,
                    employees[i].salary) < 0)
        {
            printf("Error saving employee records.\n");
            fclose(fp);
            return;
        }
    }

    if (fclose(fp) != 0)
    {
        perror("Error closing employees file");
        return;
    }

    printf("\n%d employee(s) saved successfully.\n",
           totalEmployees);
}
