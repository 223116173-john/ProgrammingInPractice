#include "utilities.h"
#include <ctype.h>
#include <errno.h>
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#ifdef _WIN32
#include <direct.h>
#else
#include <sys/stat.h>
#include <sys/types.h>
#endif

static int getLine(const char *prompt, char *out, size_t length)
{
    size_t n;
    int ch;
    printf("%s", prompt);
    fflush(stdout);
    if (fgets(out, (int)length, stdin) == NULL) return 0;
    n = strlen(out);
    if (n > 0 && out[n-1] == '\n') { out[n-1] = '\0'; return 1; }
    if (feof(stdin)) return 1;
    /* Reject oversized input instead of allowing remnants into the next prompt. */
    while ((ch = getchar()) != '\n' && ch != EOF) {}
    printf("Input too long.\n");
    return 0;
}

int promptInt(const char *prompt, int *out)
{
    char buf[128], *end;
    long value;
    if (!getLine(prompt, buf, sizeof buf)) return 0;
    errno = 0;
    value = strtol(buf, &end, 10);
    while (isspace((unsigned char)*end)) end++;
    if (end == buf || *end != '\0' || errno || value < INT_MIN || value > INT_MAX) {
        printf("Invalid whole number.\n"); return 0;
    }
    *out = (int)value;
    return 1;
}

int promptDouble(const char *prompt, double *out)
{
    char buf[128], *end;
    double value;
    if (!getLine(prompt, buf, sizeof buf)) return 0;
    errno = 0;
    value = strtod(buf, &end);
    while (isspace((unsigned char)*end)) end++;
    if (end == buf || *end != '\0' || errno || value != value || value < 0 || value > 1e15) {
        printf("Invalid amount (must be non-negative).\n"); return 0;
    }
    *out = value;
    return 1;
}

int promptText(const char *prompt, char *out, size_t capacity)
{
    char buf[256];
    size_t n;
    if (!getLine(prompt, buf, sizeof buf)) return 0;
    n = strlen(buf);
    if (n == 0 || n >= capacity || strchr(buf, '|') != NULL) {
        printf("Enter 1 to %zu characters; do not use |.\n", capacity-1);
        return 0;
    }
    memcpy(out, buf, n+1);
    return 1;
}

int promptDate(const char *title, int *day, int *month, int *year)
{
    printf("%s\n", title);
    if (!promptInt("  Day: ", day) || !promptInt("  Month: ", month) ||
        !promptInt("  Year: ", year)) return 0;
    if (*day < 1 || *day > 31 || *month < 1 || *month > 12 || *year < 1900 || *year > 2200) {
        printf("Invalid date.\n"); return 0;
    }
    return 1;
}

int ensureDataDirectory(void)
{
    int result;
#ifdef _WIN32
    result = _mkdir("data");
#else
    result = mkdir("data", 0777);
#endif
    if (result == 0 || errno == EEXIST) return 1;
    perror("Cannot create data directory");
    return 0;
}
