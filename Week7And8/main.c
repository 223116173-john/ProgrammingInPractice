
#include <stdio.h>
#include <string.h>

char supplierNames[5][100];
char supplierEmails[5][100];
char supplierPhones[5][30];
char supplierTowns[5][50];
int supplierCount = 0;

void displayWelcome(void);
void displayMenu(void);
void supplierMenu(void);
void addSupplier(void);
void displaySupplier(void);
void searchSupplier(void);
void showNameLength(void);
float calculateVAT(float amount);
float calculateSalary(float basic, float housing, float transport);
float calculateBudget(float revenue, float expenses);
int searchEmployee(int id, int ids[], int size);

int main(void)
{
    int choice, employeeID, position;
    int employeeIDs[] = {101, 102, 103, 104, 105};
    float amount, basic, housing, transport, revenue, expenses, balance;

    displayWelcome();

    do
    {
        displayMenu();
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                printf("Enter basic salary: ");
                scanf("%f", &basic);
                printf("Enter housing allowance: ");
                scanf("%f", &housing);
                printf("Enter transport allowance: ");
                scanf("%f", &transport);
                printf("Gross salary: %.2f\n", calculateSalary(basic, housing, transport));
                break;

            case 2:
                printf("Enter amount: ");
                scanf("%f", &amount);
                printf("VAT: %.2f\n", calculateVAT(amount));
                break;

            case 3:
                printf("Enter revenue: ");
                scanf("%f", &revenue);
                printf("Enter expenses: ");
                scanf("%f", &expenses);
                balance = calculateBudget(revenue, expenses);
                printf("Budget balance: %.2f\n", balance);

                if (balance > 0)
                    printf("SURPLUS\n");
                else if (balance < 0)
                    printf("DEFICIT\n");
                else
                    printf("BALANCED\n");
                break;

            case 4:
                printf("Enter employee ID: ");
                scanf("%d", &employeeID);
                position = searchEmployee(employeeID, employeeIDs, 5);

                if (position == -1)
                    printf("Employee not found.\n");
                else
                    printf("Employee found at position %d.\n", position);
                break;

            case 5:
                supplierMenu();
                break;

            case 6:
                printf("Goodbye.\n");
                break;

            default:
                printf("Invalid choice.\n");
        }

    } while (choice != 6);

    return 0;
}

void displayWelcome(void)
{
    printf("Welcome to the Municipal Financial Management System\n");
}

void displayMenu(void)
{
    printf("\nMUNICIPAL FINANCIAL MANAGEMENT SYSTEM\n");
    printf("1. Calculate Employee Salary\n");
    printf("2. Calculate VAT\n");
    printf("3. Calculate Budget\n");
    printf("4. Search Employee\n");
    printf("5. Supplier Management\n");
    printf("6. Exit\n");
    printf("Enter choice: ");
}

void supplierMenu(void)
{
    int choice;

    do
    {
        printf("\nSupplier Management\n");
        printf("1. Add Supplier\n");
        printf("2. Display Supplier\n");
        printf("3. Search Supplier\n");
        printf("4. Show Name Length\n");
        printf("5. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                addSupplier();
                break;

            case 2:
                displaySupplier();
                break;

            case 3:
                searchSupplier();
                break;

            case 4:
                showNameLength();
                break;

            case 5:
                break;

            default:
                printf("Invalid choice.\n");
        }

    } while (choice != 5);
}

void addSupplier(void)
{
    if (supplierCount == 5)
    {
        printf("The five supplier spaces are full.\n");
        return;
    }

    getchar();

    printf("Enter supplier name: ");
    fgets(supplierNames[supplierCount], 100, stdin);

    printf("Enter email: ");
    fgets(supplierEmails[supplierCount], 100, stdin);

    printf("Enter phone: ");
    fgets(supplierPhones[supplierCount], 30, stdin);

    printf("Enter town: ");
    fgets(supplierTowns[supplierCount], 50, stdin);

    supplierNames[supplierCount][strcspn(supplierNames[supplierCount], "\n")] = '\0';
    supplierEmails[supplierCount][strcspn(supplierEmails[supplierCount], "\n")] = '\0';
    supplierPhones[supplierCount][strcspn(supplierPhones[supplierCount], "\n")] = '\0';
    supplierTowns[supplierCount][strcspn(supplierTowns[supplierCount], "\n")] = '\0';

    supplierCount++;

    printf("Supplier added.\n");
}

void displaySupplier(void)
{
    char backup[100];
    char description[200];
    int i;

    if (supplierCount == 0)
    {
        printf("No suppliers added yet.\n");
        return;
    }

    for (i = 0; i < supplierCount; i++)
    {
        strcpy(backup, supplierNames[i]);

        strcpy(description, supplierNames[i]);
        strcat(description, " operates in ");
        strcat(description, supplierTowns[i]);
        strcat(description, ".");

        printf("\nSupplier %d\n", i + 1);
        printf("Name: %s\n", supplierNames[i]);
        printf("Email: %s\n", supplierEmails[i]);
        printf("Phone: %s\n", supplierPhones[i]);
        printf("Town: %s\n", supplierTowns[i]);
        printf("Copied name: %s\n", backup);
        printf("%s\n", description);
    }
}

void searchSupplier(void)
{
    char name[100];
    int i, found = 0;

    getchar();

    printf("Enter supplier name to search: ");
    fgets(name, sizeof(name), stdin);

    name[strcspn(name, "\n")] = '\0';

    for (i = 0; i < supplierCount; i++)
    {
        if (strcmp(supplierNames[i], name) == 0)
        {
            printf("Supplier found.\n");
            found = 1;
            break;
        }
    }

    if (!found)
        printf("Supplier not found.\n");
}

void showNameLength(void)
{
    int i;

    if (supplierCount == 0)
    {
        printf("No suppliers added yet.\n");
        return;
    }

    for (i = 0; i < supplierCount; i++)
    {
        printf("\n%s\n", supplierNames[i]);
        printf("Supplier name length: %zu\n", strlen(supplierNames[i]));
        printf("Email length: %zu\n", strlen(supplierEmails[i]));
        printf("Town length: %zu\n", strlen(supplierTowns[i]));
    }
}

float calculateVAT(float amount)
{
    return amount * 0.15f;
}

float calculateSalary(float basic, float housing, float transport)
{
    return basic + housing + transport;
}

float calculateBudget(float revenue, float expenses)
{
    return revenue - expenses;
}

int searchEmployee(int id, int ids[], int size)
{
    int i;

    for (i = 0; i < size; i++)
    {
        if (ids[i] == id)
            return i;
    }

    return -1;
}
