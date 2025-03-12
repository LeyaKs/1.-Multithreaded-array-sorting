#include <stdio.h>
#include <fcntl.h>
#include <errno.h>
#include <sys/types.h>
#include <string.h>
#include <sys/wait.h>
#include <unistd.h> 

#define BUFFER_SIZE 256

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "File name reading error \n");
        return 1;
    }
    char *input_filename = argv[1];
    FILE *input_file = fopen(input_filename, "r");

    if (input_file == NULL) {
        printf("Error code: %d\n", errno);
        printf("Error message: %s\n", strerror(errno));
    }

    pid_t pid = fork();

    if (pid == -1) {
        fprintf(stderr, "Forking process error \n");
        return 1;
    }

    if (pid == 0) {
        FILE *child_file = fopen("child.txt", "wr");
        if (child_file == NULL) {
            printf("Error code in child file: %d\n", errno);
            printf("Error message in child file: %s\n", strerror(errno));
            return 1;
        }

        char buffer[BUFFER_SIZE];
        size_t bytes_read;
        fseek(input_file, 0, SEEK_SET);
        while ((bytes_read = fread(buffer, 1, BUFFER_SIZE, input_file)) > 0) {
            fwrite(buffer, 1, bytes_read, child_file);
        }
        fclose(input_file);
        
        wait(NULL);
        fseek(child_file, 0, SEEK_SET);
        while ((bytes_read = fread(buffer, 1, BUFFER_SIZE, child_file)) > 0) {
            fwrite(buffer, 1, bytes_read, stdout);
        }
        fclose(child_file);
    } else {
        FILE *parent_file = fopen("parent.txt", "wr");
        if (parent_file == NULL) {
            printf("Error code in parent file: %d\n", errno);
            printf("Error message in parent file: %s\n", strerror(errno));
            return 1;
        }

        char buffer[BUFFER_SIZE];
        size_t bytes_read;
        fseek(input_file, 0, SEEK_SET);
        while ((bytes_read = fread(buffer, 1, BUFFER_SIZE, input_file)) > 0) {
            fwrite(buffer, 1, bytes_read, parent_file);
        }
        fclose(input_file);
        
        wait(NULL);
        fseek(parent_file, 0, SEEK_SET);
        while ((bytes_read = fread(buffer, 1, BUFFER_SIZE, parent_file)) > 0) {
            fwrite(buffer, 1, bytes_read, stdout);
        }
        fclose(parent_file);
    }
    return 0;
}