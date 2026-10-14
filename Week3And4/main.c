
#include <stdio.h>

int main(void)
{
    float basicSalary, housing, transport, tax;
    float grossSalary, netSalary;

    char supplier1[50], supplier2[50];
    float price1, price2, budget;
    int registered1, registered2;
    int documents1, documents2;
    int qualified1, qualified2;

    printf("Enter basic salary: ");
    scanf("%f", &basicSalary);

    printf("Enter housing allowance: ");
    scanf("%f", &housing);

    printf("Enter transport allowance: ");
    scanf("%f", &transport);

    printf("Enter tax: ");
    scanf("%f", &tax);

    grossSalary = basicSalary + housing + transport;
    netSalary = grossSalary - tax;

    printf("\nGross Salary: %.2f\n", grossSalary);
    printf("Net Salary: %.2f\n", netSalary);

    if (netSalary >= 20000)
    {
        printf("High Income\n");
    }
    else
    {
        printf("Standard Income\n");
    }

    printf("\nEnter available budget: ");
    scanf("%f", &budget);

    printf("\nEnter first supplier name: ");
    scanf("%49s", supplier1);

    printf("Enter first supplier tender price: ");
    scanf("%f", &price1);

    printf("Is first supplier registered? (1=Yes, 0=No): ");
    scanf("%d", &registered1);

    printf("Are first supplier documents complete? (1=Yes, 0=No): ");
    scanf("%d", &documents1);

    printf("\nEnter second supplier name: ");
    scanf("%49s", supplier2);

    printf("Enter second supplier tender price: ");
    scanf("%f", &price2);

    printf("Is second supplier registered? (1=Yes, 0=No): ");
    scanf("%d", &registered2);

    printf("Are second supplier documents complete? (1=Yes, 0=No): ");
    scanf("%d", &documents2);

    qualified1 = registered1 == 1 && documents1 == 1 && price1 <= budget;
    qualified2 = registered2 == 1 && documents2 == 1 && price2 <= budget;

    printf("\nSupplier: %s\n", supplier1);

    if (!qualified1)
    {
        printf("Status: Disqualified\n");
    }
    else if (!qualified2 || price1 < price2)
    {
        printf("Status: Preferred Supplier\n");
    }
    else
    {
        printf("Status: Qualified\n");
    }

    printf("\nSupplier: %s\n", supplier2);

    if (!qualified2)
    {
        printf("Status: Disqualified\n");
    }
    else if (!qualified1 || price2 < price1)
    {
        printf("Status: Preferred Supplier\n");
    }
    else
    {
        printf("Status: Qualified\n");
    }

    return 0;
}
