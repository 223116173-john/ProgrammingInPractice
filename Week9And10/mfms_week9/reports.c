
#include <stdio.h>
#include "reports.h"
#include "employees.h"
#include "budget.h"

void employeeReport(void)
{
    double totalPayroll = calculatePayrollTotal();

    printf("\nMunicipal Employee Payroll Report\n");
    printf("----------------------------------\n");

    printf("Total Monthly Payroll: N$ %.2f\n", totalPayroll);

    if (totalPayroll == 0)
    {
        printf("No payroll amount has been recorded.\n");
    }
}

void budgetReport(void)
{
    double totalBalance = calculateBudgetBalance();

    printf("\nMunicipal Budget Summary\n");
    printf("-------------------------\n");

    printf("Overall Budget Balance: N$ %.2f\n", totalBalance);

    if (totalBalance < 0)
    {
        printf("Status: Budget deficit\n");
        printf("The municipality has exceeded its allocated budget.\n");
    }
    else if (totalBalance > 0)
    {
        printf("Status: Budget surplus\n");
        printf("The municipality has funds remaining.\n");
    }
    else
    {
        printf("Status: Zero balance\n");
    }
}
