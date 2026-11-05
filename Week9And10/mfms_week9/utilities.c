
#include <stdio.h>
#include "utilities.h"

static void clearInputBuffer(void)
{
    int ch;

    while ((ch = getchar()) != '\n' && ch != EOF)
    {
    }
}

int readInt(void)
{
    int number;

    while (scanf("%d", &number) != 1)
    {
        if (feof(stdin))
        {
            return 0;
        }

        printf("Invalid input. Enter a whole number: ");
        clearInputBuffer();
    }

    clearInputBuffer();
    return number;
}

double readDouble(void)
{
    double number;

    while (scanf("%lf", &number) != 1)
    {
        if (feof(stdin))
        {
            return 0.0;
        }

        printf("Invalid input. Enter a valid amount: ");
        clearInputBuffer();
    }

    clearInputBuffer();
    return number;
}

void pauseScreen(void)
{
    printf("\nPress Enter to continue...");
    fflush(stdout);
    getchar();
}
