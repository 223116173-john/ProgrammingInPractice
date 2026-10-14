
#include <stdio.h>
#include <string.h>

int main(void)
{
    float salaries[50];
    float budgets[10];
    char registrations[20][20];
    char searchRegistration[20];

    float totalSalary = 0;
    float averageSalary;
    float highestSalary, lowestSalary;
    float searchSalary, tempSalary;

    float totalBudget = 0;
    float averageBudget, tempBudget;

    int i, j, found;

    printf("Municipal Employee Salary Analysis\n");

    for (i = 0; i < 50; i++)
    {
        printf("Enter salary for employee %d: ", i + 1);
        scanf("%f", &salaries[i]);

        totalSalary += salaries[i];

        if (i == 0)
        {
            highestSalary = salaries[i];
            lowestSalary = salaries[i];
        }

        if (salaries[i] > highestSalary)
        {
            highestSalary = salaries[i];
        }

        if (salaries[i] < lowestSalary)
        {
            lowestSalary = salaries[i];
        }
    }

    averageSalary = totalSalary / 50;

    printf("\nEmployee Salaries\n");

    for (i = 0; i < 50; i++)
    {
        printf("Employee %d: %.2f\n", i + 1, salaries[i]);
    }

    printf("\nSalary Report\n");
    printf("Total salary expenditure: %.2f\n", totalSalary);
    printf("Average salary: %.2f\n", averageSalary);
    printf("Highest salary: %.2f\n", highestSalary);
    printf("Lowest salary: %.2f\n", lowestSalary);

    printf("\nEnter salary to search: ");
    scanf("%f", &searchSalary);

    found = 0;

    for (i = 0; i < 50; i++)
    {
        if (salaries[i] == searchSalary)
        {
            printf("Salary found at employee %d\n", i + 1);
            found = 1;
            break;
        }
    }

    if (found == 0)
    {
        printf("Salary not found.\n");
    }

    for (i = 0; i < 49; i++)
    {
        for (j = 0; j < 49 - i; j++)
        {
            if (salaries[j] > salaries[j + 1])
            {
                tempSalary = salaries[j];
                salaries[j] = salaries[j + 1];
                salaries[j + 1] = tempSalary;
            }
        }
    }

    printf("\nSalaries from Lowest to Highest\n");

    for (i = 0; i < 50; i++)
    {
        printf("%.2f\n", salaries[i]);
    }

    printf("\nMunicipal Department Budgets\n");

    for (i = 0; i < 10; i++)
    {
        printf("Enter budget for department %d: ", i + 1);
        scanf("%f", &budgets[i]);

        totalBudget += budgets[i];
    }

    averageBudget = totalBudget / 10;

    printf("\nDepartment Budgets\n");

    for (i = 0; i < 10; i++)
    {
        printf("Department %d: %.2f\n", i + 1, budgets[i]);
    }

    printf("\nTotal municipal budget: %.2f\n", totalBudget);
    printf("Average department budget: %.2f\n", averageBudget);

    for (i = 0; i < 9; i++)
    {
        for (j = 0; j < 9 - i; j++)
        {
            if (budgets[j] > budgets[j + 1])
            {
                tempBudget = budgets[j];
                budgets[j] = budgets[j + 1];
                budgets[j + 1] = tempBudget;
            }
        }
    }

    printf("\nBudgets from Lowest to Highest\n");

    for (i = 0; i < 10; i++)
    {
        printf("%.2f\n", budgets[i]);
    }

    printf("\nMunicipal Vehicle Registrations\n");

    for (i = 0; i < 20; i++)
    {
        printf("Enter vehicle registration %d: ", i + 1);
        scanf("%19s", registrations[i]);
    }

    printf("\nVehicle Registration Numbers\n");

    for (i = 0; i < 20; i++)
    {
        printf("%s\n", registrations[i]);
    }

    printf("\nEnter registration number to search: ");
    scanf("%19s", searchRegistration);

    found = 0;

    for (i = 0; i < 20; i++)
    {
        if (strcmp(registrations[i], searchRegistration) == 0)
        {
            printf("Registration found at position %d\n", i + 1);
            found = 1;
            break;
        }
    }

    if (found == 0)
    {
        printf("Registration number not found.\n");
    }

    return 0;
}
