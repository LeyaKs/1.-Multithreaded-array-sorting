#include <stdio.h>
#include <stdlib.h>
#include "file_operations.h"
#include "string_operations.h"



int main(int argc, char *argv[]) {
    int sort_index = -1, num_lines;
    const char *input_file = argv[1];
    const char *output_file = argv[2];
    const char *sort_method = argv[3];

    int (*compare_funcs[])(const void*, const void*) = {
        compare_alphabetical,
        compare_length,
        compare_reverse_alphabetical
    };

    const char *sorting_method[] = {
        "alphabetical",
        "length",
        "reverse_alphabetical"
    };
    for (int i = 0; i < (int)(sizeof(sorting_method) / sizeof(sorting_method[0])); ++i) {
        if (strcmp(sort_method, sorting_method[i]) == 0) {
            sort_index = i;
            break;
        }
    }


    if (argc != 4) {
        fprintf(stderr, "File name reading error \n");
        return 1;
    }


    char **lines = read_from_file(input_file, &num_lines);
    if (!lines) return 1;

    if (sort_index != -1) {
        qsort(lines, num_lines, sizeof(char *), compare_funcs[sort_index]);
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