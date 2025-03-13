#include "string_operations.h"

char *trim(char *str) {
    size_t len = strlen(str);
    size_t start = 0;
    size_t end = len -1;

    while (start < len && isspace(str[start])) ++start;
    while (end >= start && isspace(str[end])) --end;

    str[end+1] = '\0';
    return str + start;
}

int compare_strings(const void *a, const void *b) {
    return strcmp(*(const char **)a, *(const char **)b);
}