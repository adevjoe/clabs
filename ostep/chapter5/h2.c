#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h>

int main() {
    int fd = open("h2.output", O_CREAT | O_RDWR | O_TRUNC, S_IRWXU);
    int cp = fork();
    if (cp == 0) {
        printf("child fd: %d\n", fd);
        write(fd, "child", 5);
    } else {
        wait(NULL);
        printf("parent fd: %d\n", fd);
        write(fd, "parent", 6);
        close(fd);
    }
    return 0;
}