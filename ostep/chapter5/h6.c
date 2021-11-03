#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    int pid = fork();
    if (pid == 0) {
        printf("child pid: %d\n", getpid());
    } else {
        int wc = waitpid(pid, NULL, 0);
        printf("parent pid: %d, wc: %d\n", getpid(), wc);
    }
}