#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 256

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

    FILE *fp = fopen(input_file, "r");
    if (!fp) {
        fprintf(stderr,"Input file reading error");
        return 1;
    }

    char buffer[BUFFER_SIZE];
    size_t bytes_read;
    while ((bytes_read = fread(buffer, 1, BUFFER_SIZE, fp)) > 0) {
        if (num_lines == lines_capacity) {
            lines_capacity *= 2;
            char **temp = (char **)realloc(lines, lines_capacity * sizeof(char *));
            if (!temp) {
                fprintf(stderr,"Input file realloc error");
                for (int i = 0; i < num_lines; i++) {
                    free(lines[i]);
                }
                free(lines);
                fclose(fp);
                return 1;
            }
            lines = temp;
        }
        lines[num_lines] = strdup(buffer);
    }
    fclose(fp);


    return 0;
}