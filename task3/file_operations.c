#include "file_operations.h"

#define BUFFER_SIZE 256


char **read_from_file(const char *file, int *num_lines) {
    char **lines = NULL;
    char buffer[BUFFER_SIZE];
    int lines_capacity = 10;
    lines = (char **)malloc(lines_capacity * sizeof(char *));
    if (!lines) {
        fprintf(stderr,"Memory error");
        return NULL;
    }
    FILE *input_fp = fopen(file, "r");
    if (!input_fp) return NULL;

    while (fgets(buffer, BUFFER_SIZE, input_fp)) {
        char *trimmed_line = trim(buffer);
        if (strlen(trimmed_line) > 0) {
            if ((*num_lines) == lines_capacity) {
                lines_capacity *= 2;
                char **temp = (char **)realloc(lines, lines_capacity * sizeof(char *));
                lines = temp;
            }
            lines[*num_lines] = strdup(trimmed_line);
            (*num_lines)++;
        }
    }
    fclose(input_fp);
    return lines;
}



int write_to_file(char **lines, int num_lines, const char *file) {
    FILE *output_fp = fopen(file, "w");
    if (!output_fp) return 1;
    for (int i = 0; i < num_lines; ++i) {
        fprintf(output_fp, "%s\n", lines[i]);
        printf("%s\n", lines[i]);
    }
    fclose(output_fp);
    return 0;
}

void free_lines(char **lines, int num_lines) {
    if (lines != NULL) {
        for (int i = 0; i < num_lines; ++i) {
            free(lines[i]);
        }
        free(lines);
    }
}