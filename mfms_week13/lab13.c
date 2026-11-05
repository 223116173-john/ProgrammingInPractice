/* Week 13: self-contained implementation of the five TODOs from the handout. */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int id;
    char name[30];
    double salary;
} Employee;

int main(void)
{
    size_t capacity = 2, count = 0, i;
    Employee *employees = malloc(capacity * sizeof *employees);
    Employee e;
    if (employees == NULL) { puts("Out of memory!"); return 1; }

    for (;;) {
        printf("Employee ID (0 to stop): ");
        if (scanf("%d", &e.id) != 1) { puts("Invalid input."); free(employees); return 1; }
        if (e.id == 0) break;
        if (e.id < 0) { puts("ID must be positive."); continue; }
        printf("Name (one word): ");
        if (scanf("%29s", e.name) != 1) { free(employees); return 1; }
        printf("Salary: ");
        if (scanf("%lf", &e.salary) != 1 || e.salary < 0 || e.salary != e.salary) {
            puts("Invalid salary."); free(employees); return 1;
        }
        for (i=0;i<count;i++) if (employees[i].id == e.id) break;
        if (i < count) { puts("Duplicate employee ID."); continue; }
        if (count == capacity) {
            Employee *bigger;
            if (capacity > ((size_t)-1)/sizeof *employees/2) {
                puts("Too many records."); free(employees); return 1;
            }
            bigger = realloc(employees, capacity * 2 * sizeof *employees);
            if (bigger == NULL) { puts("Out of memory!"); free(employees); return 1; }
            employees = bigger;
            capacity *= 2;
            printf("(grown to %zu slots)\n", capacity);
        }
        employees[count++] = e;
    }
    for (i=0;i<count;i++)
        printf("%d %-29s N$%.2f\n", employees[i].id, employees[i].name, employees[i].salary);
    printf("Employees: %zu | Capacity: %zu\n", count, capacity);
    free(employees);
    employees = NULL;
    return 0;
}
