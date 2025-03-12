#include "file_operations.h"

#define BUFFER_SIZE 256

void copy_file(FILE *input_file, FILE *output_file) {
    char buffer[BUFFER_SIZE];
    size_t bytes_read;
    fseek(input_file, 0, SEEK_SET);
    while ((bytes_read = fread(buffer, 1, BUFFER_SIZE, input_file)) > 0) {
        fwrite(buffer, 1, bytes_read, output_file);
    }
    return;
}

void print_file(FILE *file) {
    char buffer[BUFFER_SIZE];
    size_t bytes_read;
    fseek(file, 0, SEEK_SET);
    while ((bytes_read = fread(buffer, 1, BUFFER_SIZE, file)) > 0) {
        fwrite(buffer, 1, bytes_read, stdout);
    }
    return;
}