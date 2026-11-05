
#include <stdio.h>
#include <string.h>
#include "budget.h"

#define MAX_BUDGETS 30

typedef struct
{
    char department[50];
    double allocatedAmount;
    double amountSpent;
} Budget;

static Budget budgets[MAX_BUDGETS];
static int totalBudgets = 0;

void addBudget(void)
{
    if (totalBudgets >= MAX_BUDGETS)
    {
        printf("Budget register is full.\n");
        return;
    }

    Budget newBudget;

    printf("\nEnter department name: ");
    if (scanf(" %49[^\n]", newBudget.department) != 1)
    {
        printf("Invalid department name.\n");
        return;
    }

    for (int i = 0; i < totalBudgets; i++)
    {
        if (strcmp(budgets[i].department,
                   newBudget.department) == 0)
        {
            printf("This department already has a budget.\n");
            return;
        }
    }

    printf("Enter allocated budget (N$): ");
    if (scanf("%lf", &newBudget.allocatedAmount) != 1 ||
        newBudget.allocatedAmount < 0)
    {
        printf("Invalid budget amount.\n");
        return;
    }

    printf("Enter amount already spent (N$): ");
    if (scanf("%lf", &newBudget.amountSpent) != 1 ||
        newBudget.amountSpent < 0)
    {
        printf("Invalid expenditure amount.\n");
        return;
    }

    budgets[totalBudgets] = newBudget;
    totalBudgets++;

    printf("Department budget added successfully.\n");
}

void listBudgets(void)
{
    if (totalBudgets == 0)
    {
        printf("\nNo department budgets recorded yet.\n");
        return;
    }

    printf("\nMunicipal Department Budgets\n");
    printf("--------------------------------\n");

    for (int i = 0; i < totalBudgets; i++)
    {
        double balance = budgets[i].allocatedAmount -
                         budgets[i].amountSpent;

        printf("\nDepartment: %s\n",
               budgets[i].department);
        printf("Allocated: N$ %.2f\n",
               budgets[i].allocatedAmount);
        printf("Spent: N$ %.2f\n",
               budgets[i].amountSpent);
        printf("Remaining Balance: N$ %.2f\n", balance);

        if (balance < 0)
        {
            printf("Status: Over budget\n");
        }
        else
        {
            printf("Status: Within budget\n");
        }
    }

    printf("\nTotal departments: %d\n", totalBudgets);
}

double calculateBudgetBalance(void)
{
    double totalBalance = 0.0;

    for (int i = 0; i < totalBudgets; i++)
    {
        totalBalance += budgets[i].allocatedAmount -
                        budgets[i].amountSpent;
    }

    return totalBalance;
}
