#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define BUFFER_SIZE 256

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


int main(int argc, char *argv[]) {
    if (argc != 4) {
        fprintf(stderr, "File name reading error \n");
        return 1;
    }

    const char *input_file = argv[1];
    const char *output_file = argv[2];
    const char *sort_method = argv[3];

    char **lines = NULL;
    int num_lines = 0;
    int lines_capacity = 10;
    lines = (char **)malloc(lines_capacity * sizeof(char *));
    if (!lines) {
        fprintf(stderr,"Memory error");
        return 1;
    }

    FILE *input_fp = fopen(input_file, "r");
    if (!input_fp) {
        fprintf(stderr,"Input file opening error");
        return 1;
    }

    char buffer[BUFFER_SIZE];
    
    while (fgets(buffer, BUFFER_SIZE, input_fp) != NULL) {
        char *trimmed_line = trim(buffer);
        if (strlen(trimmed_line) > 0) {
            if (num_lines == lines_capacity) {
                lines_capacity *= 2;
                char **temp = (char **)realloc(lines, lines_capacity * sizeof(char *));
                lines = temp;
            }
            lines[num_lines] = strdup(buffer);
            num_lines++;
            
        }
    }

    if (strcmp(sort_method, "alphabetical") == 0) {
        qsort(lines, num_lines, sizeof(char *), compare_strings);
    } else { 
        fprintf(stderr, "Unknown sorting method");
        fclose(input_fp);
    }


    FILE *output_fp = fopen(output_file, "w");
    if (output_fp == NULL) {
        perror("Output file opening error");
        for (int i = 0; i < num_lines; ++i) {
            free(lines[i]);
        }
        free(lines);
        return 1;
    }

    for (int i = 0; i < num_lines; ++i) {
        fprintf(output_fp, "%s\n", lines[i]);
        printf("%s\n", lines[i]);
    }

    fclose(output_fp);
    fclose(input_fp);


    for (int i = 0; i < num_lines; ++i) {
        free(lines[i]);
    }
    free(lines);


    return 0;
}