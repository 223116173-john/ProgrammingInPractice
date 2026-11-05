#include "pointers.h"
#include <stdio.h>
#include <stdlib.h>

/* By value: both parameters are copies, so the caller is unchanged. */
void swapSalariesWrong(double a, double b)
{
    double temp = a;
    a = b;
    b = temp;
    printf("Inside wrong swap: %.2f, %.2f (only copies swapped)\n", a, b);
}

/* By address: change the original salaries through pointers. */
void swapSalaries(double *a, double *b)
{
    double temp = *a;
    *a = *b;
    *b = temp;
}

void displaySalaries(const double salaries[], size_t n)
{
    size_t i;
    for (i=0;i<n;i++) printf(" Employee %zu: N$%.2f\n", i+1, salaries[i]);
}

double findHighest(const double salaries[], size_t n)
{
    size_t i; double highest;
    if (n == 0) return 0.0;
    highest = salaries[0];
    for (i=1;i<n;i++) if (salaries[i] > highest) highest = salaries[i];
    return highest;
}

double calculateAverage(const double salaries[], size_t n)
{
    double sum = 0; size_t i;
    if (n == 0) return 0.0;
    for (i=0;i<n;i++) sum += salaries[i];
    return sum / n;
}

void giveRaise(double salaries[], size_t n, double percent)
{
    size_t i;
    for (i=0;i<n;i++) salaries[i] *= 1.0 + percent/100.0;
}

void updateSalary(Employee *e, double newSalary)
{
    if (e != NULL && newSalary >= 0) e->salary = newSalary;
}

Employee *findEmployee(Employee list[], size_t n, int id)
{
    size_t i;
    for (i=0;i<n;i++) if (list[i].id == id) return &list[i];
    return NULL;
}

void pointerDemonstration(void)
{
    int number = 25;
    int *p = &number;
    double salaries[3] = {15000.00, 18500.50, 21000.75};
    double a = 15000, b = 21000;

    printf("Pointer warm-up: value=%d, address=%p, *p=%d\n",
           number, (void *)&number, *p);
    *p = 30;
    printf("After *p=30: number=%d\n", number);
    printf("Before wrong swap: %.2f, %.2f\n", a, b);
    swapSalariesWrong(a, b);
    printf("After wrong swap: %.2f, %.2f (unchanged)\n", a, b);
    swapSalaries(&a, &b);
    printf("After correct swap: %.2f, %.2f\n", a, b);

    puts("Original salary array:");
    displaySalaries(salaries, 3);
    printf("Highest: N$%.2f | Average: N$%.2f\n",
           findHighest(salaries, 3), calculateAverage(salaries, 3));
    giveRaise(salaries, 3, 10);
    puts("After 10 percent raise (the original array changed):");
    displaySalaries(salaries, 3);

    /* calloc demonstrates zero-initialized heap memory, then free(). */
    {
        int *counters = calloc(3, sizeof *counters);
        if (counters == NULL) puts("calloc failed.");
        else {
            printf("calloc example (three zero counters): %d %d %d\n",
                   counters[0], counters[1], counters[2]);
            free(counters);
            counters = NULL;
        }
    }
}
