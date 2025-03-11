#include "output_info.h"

void output_info(const struct stat *file_info, const char *filename) {
    printf("File name: %s\n", filename);
    printf("File size: %lld байт\n", (long long)file_info->st_size);
    printf("Last change: %s", ctime(&file_info->st_mtime));

    output_file_type(file_info);
    output_owner_name(file_info);
    output_file_permissions(file_info);

    
}

void output_file_type(const struct stat *file_info) {
    printf("File type: ");

    if (S_ISREG(file_info->st_mode)) {
        printf("Regular file\n");
    } else if (S_ISDIR(file_info->st_mode)) {
        printf("Directory\n");
    } else if (S_ISBLK(file_info->st_mode)) {
        printf("Block device\n");
    } else if (S_ISFIFO(file_info->st_mode)) {
        printf("FIFO/pipe\n");
    } else if (S_ISLNK(file_info->st_mode)) {
        printf("Symbolic link\n");
    } else if (S_ISSOCK(file_info->st_mode)) {
        printf("Socket\n");
    } else {
        printf("Unknown\n");
    }
}

void output_owner_name(const struct stat *file_info) {
    struct passwd *owner = getpwuid(file_info->st_uid);
    if (owner) {
        printf("Owner: %s\n", owner->pw_name);
    } else {
        printf("Owner (UID): %d\n", file_info->st_uid);
    }
}

void output_file_permissions(const struct stat *file_info) {
    printf("Permissions: ");
    printf( (S_ISDIR(file_info->st_mode)) ? "d" : (S_ISLNK(file_info->st_mode) ? "l" : "-"));
    printf( (file_info->st_mode & S_IRUSR) ? "r" : "-");
    printf( (file_info->st_mode & S_IWUSR) ? "w" : "-");
    printf( (file_info->st_mode & S_IXUSR) ? "x" : "-");
    printf( (file_info->st_mode & S_IRGRP) ? "r" : "-");
    printf( (file_info->st_mode & S_IWGRP) ? "w" : "-");
    printf( (file_info->st_mode & S_IXGRP) ? "x" : "-");
    printf( (file_info->st_mode & S_IROTH) ? "r" : "-");
    printf( (file_info->st_mode & S_IWOTH) ? "w" : "-");
    printf( (file_info->st_mode & S_IXOTH) ? "x" : "-");
    printf("\n");
  }