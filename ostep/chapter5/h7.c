#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    int pid = fork();
    if (pid == 0) {
        close(STDOUT_FILENO);
        printf("Hello, world!\n");
    } else {
        wait(NULL);
    }
}