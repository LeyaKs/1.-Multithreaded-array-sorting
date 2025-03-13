#include <stdio.h>
#include <stdlib.h>
// #include <string.h>
// #include <ctype.h>

#include "file_operations.h"


int main(int argc, char *argv[]) {
    if (argc != 4) {
        fprintf(stderr, "File name reading error \n");
        return 1;
    }

    const char *input_file = argv[1];
    const char *output_file = argv[2];
    const char *sort_method = argv[3];

    int num_lines;
    char **lines = read_from_file(input_file, &num_lines);
    if (!lines) return 1;
    if (strcmp(sort_method, "alphabetical") == 0) {
        qsort(lines, num_lines, sizeof(char *), compare_strings);
    } else { 
        fprintf(stderr, "Unknown sorting method");
        free_lines(lines, num_lines);
        return 1;
    }

    if (write_to_file(lines, num_lines, output_file) != 0) {
        fprintf(stderr, "Error writing to output file");
        free_lines(lines, num_lines);
        return 1;
    }

    free_lines(lines, num_lines);
    return 0;
}