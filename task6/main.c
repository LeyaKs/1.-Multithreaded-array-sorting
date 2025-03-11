#include <stdio.h>
#include <sys/stat.h>
#include "output_info.h"


int main(int argc, char *argv[]) {
    struct stat file_info;
    if (argc != 2) {
        fprintf(stderr, "File name reading error \n");
        return 1;
    }

    if (stat(argv[1], &file_info) == -1) {
        perror("Error stat");
        return 1;
    }

    output_info(&file_info, argv[1]);

    

    return 0;
}