#include "records.h"
#include "utilities.h"
#include <stdio.h>
#include "pointers.h"


static void displayMainMenu(void)
{
    puts("\n========== MUNICIPAL FINANCIAL MANAGEMENT SYSTEM ==========");
    puts(" 1. Add Employee                 2. View Employees");
    puts(" 3. Add Supplier                 4. View Suppliers");
    puts(" 5. Add Asset                    6. View Assets");
    puts(" 7. Add Department Budget        8. View Department Budgets");
    puts(" 9. Add Project                 10. View Projects");
    puts("11. Save Employees (binary)     12. Load Employees (binary)");
    puts("13. Employee Payroll Report     14. Municipal Budget Report");
    puts("19. Save Employees (text)       20. Load Employees (text)");

    puts("15. Update Employee Salary      16. Pointer Lab Demonstration");
    puts("17. Give All Employees a Raise  18. Search Employee by ID");

    puts(" 0. Exit System");
    puts("-----------------------------------------------------------");
}

int main(void)
{
    int choice;
    if (!initializeRecords()) return 1;
    for (;;) {
        displayMainMenu();
        if (!promptInt("Enter your choice: ", &choice)) {
            if (feof(stdin)) break;
            puts("Please enter a valid menu number.");
            continue;
        }
        switch(choice) {
        case 1: addEmployee(); break;
        case 2: displayEmployees(); break;
        case 3: addSupplier(); break;
        case 4: displaySuppliers(); break;
        case 5: addAsset(); break;
        case 6: displayAssets(); break;
        case 7: addBudget(); break;
        case 8: displayBudgets(); break;
        case 9: addProject(); break;
        case 10: displayProjects(); break;
        case 11: saveEmployeesBinary(); break;
        case 12: loadEmployeesBinary(); break;
        case 13: payrollReport(); break;
        case 14: municipalBudgetReport(); break;
        case 19: saveEmployeesText(); break;
        case 20: loadEmployeesText(); break;

        case 15: updateEmployeeSalaryMenu(); break;
        case 16: pointerDemonstration(); break;
        case 17: giveEmployeesRaiseMenu(); break;
        case 18: searchEmployeeMenu(); break;

        case 0:
            puts("Thank you for using the system.");
            freeRecords();
            return 0;
        default: puts("Invalid choice. Try again."); break;
        }
    }
    freeRecords();
    return 0;
}
