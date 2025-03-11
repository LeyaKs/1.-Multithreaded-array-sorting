#include <stdio.h>
#include <fcntl.h>
#include <errno.h>
#include <string.h>

extern char *sys_errlist[];
extern int sys_nerr;

int main() {
    int fd = open("task5", O_RDONLY);
    if (fd == -1) {
        printf("Error code: %d\n", errno);
        printf("Error message: %s\n", strerror(errno));
        perror("File opening error");
    }
    return 0;
}