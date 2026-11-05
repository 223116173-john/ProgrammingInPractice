
#include <stdio.h>
#include "employees.h"
#include "budget.h"
#include "utilities.h"
#include "reports.h"

void displayMainMenu(void)
{
    printf("\n========================================\n");
    printf(" MUNICIPAL FINANCIAL MANAGEMENT SYSTEM\n");
    printf("========================================\n");

    printf("1. Add Employee\n");
    printf("2. View Employees\n");
    printf("3. Add Department Budget\n");
    printf("4. View Department Budgets\n");
    printf("5. View Employee Payroll Report\n");
    printf("6. View Municipal Budget Report\n");
    printf("7. Save Employees to File\n");
    printf("0. Exit System\n");

    printf("----------------------------------------\n");
}

int main(void)
{
    int choice;

    do
    {
        displayMainMenu();

        printf("Enter your choice: ");
        choice = readInt();

        switch (choice)
        {
            case 1:
                addEmployee();
                break;

            case 2:
                listEmployees();
                break;

            case 3:
                addBudget();
                break;

            case 4:
                listBudgets();
                break;

            case 5:
                employeeReport();
                break;

            case 6:
                budgetReport();
                break;

            case 7:
                saveEmployees();
                break;

            case 0:
                printf("\nThank you for using the system.\n");
                printf("Closing Municipal Financial Management System...\n");
                break;

            default:
                printf("\nInvalid choice. Please try again.\n");
                break;
        }

    } while (choice != 0);

    return 0;
}
