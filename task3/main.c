#include <stdio.h>
#include <stdlib.h>
#include "file_operations.h"
#include "string_operations.h"



int main(int argc, char *argv[]) {
    int sort_index = -1, num_lines;
    const char *input_file = argv[1];      //Writing command line arguments
    const char *output_file = argv[2];
    const char *sort_method = argv[3];

    int (*compare_funcs[])(const void*, const void*) = {    //Array of sorting functions
        compare_alphabetical,
        compare_length,
        compare_reverse_alphabetical
    };

    const char *sorting_method[] = {    //Array of sorting names
        "alphabetical",
        "length",
        "reverse_alphabetical"
    };
    for (int i = 0; i < (int)(sizeof(sorting_method) / sizeof(sorting_method[0])); ++i) {
        if (strcmp(sort_method, sorting_method[i]) == 0) {      //Find index of sorting function
            sort_index = i;
            break;
        }
    }


    if (argc != 4) {        //Error in arguments from command line
        fprintf(stderr, "File name reading error \n");
        return 1;
    }


    char **lines = read_from_file(input_file, &num_lines);      //Reading lines
    if (!lines) return 1;

    if (sort_index != -1) {     //Determine sorting type
        qsort(lines, num_lines, sizeof(char *), compare_funcs[sort_index]);     //Sorting
    } else { 
        fprintf(stderr, "Unknown sorting method");
        free_lines(lines, num_lines);
        return 1;
    }

    if (write_to_file(lines, num_lines, output_file) != 0) {        //Output to screen and terminal
        fprintf(stderr, "Error writing to output file");
        free_lines(lines, num_lines);
        return 1;
    }

    free_lines(lines, num_lines);       //Free memory
    return 0;
}