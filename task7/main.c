#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <errno.h>
#include <sys/types.h>
#include <string.h>
#include <sys/wait.h>
#include <unistd.h> 
#include "file_operations.h"



int main(int argc, char *argv[]) {
    if (argc != 2) {        //Check count of arguments
        fprintf(stderr, "File name reading error \n");
        return 1;
    }
    char *input_filename = argv[1];
    FILE *input_file = fopen(input_filename, "r");

    if (input_file == NULL) {
        printf("Error code: %d\n", errno);
        printf("Error message: %s\n", strerror(errno));
        return 1;
    }

    pid_t pid = fork();     //Create child process

    if (pid == -1) {
        fprintf(stderr, "Forking process error \n");
        fclose(input_file);
        return 1;
    }

    if (pid == 0) {         //Check if it is child process
        FILE *child_file = fopen("child.txt", "w+");        //Write into child file
        if (child_file == NULL) {
            printf("Error code in child file: %d\n", errno);
            printf("Error message in child file: %s\n", strerror(errno));
            fclose(input_file);
            exit(1);
        }
        fseek(input_file, 0, SEEK_SET);
        copy_file(input_file, child_file);
        fclose(input_file);

        print_file(child_file);
        fclose(child_file);
        exit(0);
    } else {
        FILE *parent_file = fopen("parent.txt", "w+");      //Write into parent file
        if (parent_file == NULL) {
            printf("Error code in parent file: %d\n", errno);
            printf("Error message in parent file: %s\n", strerror(errno));
            fclose(input_file);
            return 1;
        }
        fseek(input_file, 0, SEEK_SET);
        copy_file(input_file, parent_file);
        fclose(input_file);
        wait(NULL);
        print_file(parent_file);
        fclose(parent_file);
    }
    return 0;
}