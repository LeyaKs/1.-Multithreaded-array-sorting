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

int compare_alphabetical(const void *a, const void *b) {
    return strcmp(*(const char **)a, *(const char **)b);
}

int compare_length(const void *a, const void *b) {
    return strlen(*(const char **)a) - strlen(*(const char **)b);
}


int compare_reverse_alphabetical(const void *a, const void *b) {
    return strcmp(*(const char **)b, *(const char **)a);
}
