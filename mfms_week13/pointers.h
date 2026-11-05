#ifndef POINTERS_H
#define POINTERS_H
#include "records.h"
#include <stddef.h>
void swapSalaries(double *a, double *b);
void swapSalariesWrong(double a, double b);
void displaySalaries(const double salaries[], size_t n);
double findHighest(const double salaries[], size_t n);
double calculateAverage(const double salaries[], size_t n);
void giveRaise(double salaries[], size_t n, double percent);
void updateSalary(Employee *e, double newSalary);
Employee *findEmployee(Employee list[], size_t n, int id);
void pointerDemonstration(void);
#endif
