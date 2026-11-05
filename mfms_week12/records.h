#ifndef RECORDS_H
#define RECORDS_H

#include <stddef.h>

/* Week 11: related data grouped into five record types. */
#define MAX_RECORDS 100

typedef struct {
    int day;
    int month;
    int year;
} Date;

typedef struct {
    int id;
    char name[30];
    char department[20];
    double salary;
} Employee;

typedef struct {
    int id;
    char name[40];
    char email[40];
    char phone[15];
    char town[20];
} Supplier;

typedef struct {
    int id;
    char description[40];
    double value;
    Date acquired;
} Asset;

typedef struct {
    char department[20];
    double allocated;
    double spent;
} Budget;

typedef struct {
    int id;
    char title[40];
    double budget;
    Date startDate;
    Date endDate;
} Project;

int initializeRecords(void);
void freeRecords(void);
void addEmployee(void);
void displayEmployees(void);
void addSupplier(void);
void displaySuppliers(void);
void addAsset(void);
void displayAssets(void);
void addBudget(void);
void displayBudgets(void);
void addProject(void);
void displayProjects(void);
void saveEmployeesBinary(void);
void loadEmployeesBinary(void);
void saveEmployeesText(void);
void loadEmployeesText(void);
void payrollReport(void);
void municipalBudgetReport(void);
size_t getEmployeeCount(void);
Employee *getEmployeeArray(void);
void searchEmployeeMenu(void);
void updateEmployeeSalaryMenu(void);
void giveEmployeesRaiseMenu(void);

#endif
