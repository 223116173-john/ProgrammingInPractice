#ifndef UTILITIES_H
#define UTILITIES_H
#include <stddef.h>
int promptInt(const char *prompt, int *out);
int promptDouble(const char *prompt, double *out);
int promptText(const char *prompt, char *out, size_t capacity);
int promptDate(const char *title, int *day, int *month, int *year);
int ensureDataDirectory(void);
#endif
