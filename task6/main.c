#include <stdio.h>
#include <sys/stat.h>
#include <time.h>

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

    printf("File name: %s\n", argv[1]);
    printf("File type: ");

    if (S_ISREG(file_info.st_mode)) {
        printf("Regular file\n");
    } else if (S_ISDIR(file_info.st_mode)) {
        printf("Directory\n");
    } else if (S_ISBLK(file_info.st_mode)) {
        printf("Block device\n");
    } else if (S_ISFIFO(file_info.st_mode)) {
        printf("FIFO/pipe\n");
    } else if (S_ISLNK(file_info.st_mode)) {
        printf("Symbolic link\n");
    } else if (S_ISSOCK(file_info.st_mode)) {
        printf("Socket\n");
    } else {
        printf("Unknown\n");
    }

    printf("File size: %lld байт\n", (long long)file_info.st_size);
    printf("Last change: %s", ctime(&file_info.st_mtime));

    return 0;
}