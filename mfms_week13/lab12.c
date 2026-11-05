/* Week 12 pointer lab: a standalone demonstration built with pointers.c. */
#include "pointers.h"
#include <stdio.h>
int main(void)
{
    Employee list[] = {
        {1001, "Maria", "Finance", 18500.50},
        {1002, "Simon", "HR", 17200.00},
        {1003, "Anna", "Engineering", 21000.75}
    };
    Employee *match;
    pointerDemonstration();
    match = findEmployee(list, 3, 1002);
    if (match != NULL) {
        updateSalary(match, 19000.00);
        printf("Updated by pointer: %s, N$%.2f\n", match->name, match->salary);
        updateSalary(match, 20000.00);
        printf("Updated twice: %s, N$%.2f\n", match->name, match->salary);
    }
    match = findEmployee(list, 3, 9999);
    if (match == NULL) puts("Employee ID 9999 not found.");
    return 0;
}
