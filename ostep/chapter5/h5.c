#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    int pid = fork();
    if (pid == 0) {
        int wc = wait(NULL);
        printf("child pid: %d\n", getpid());
        printf("child wc: %d\n", wc); // child process wait return -1
    } else {
        int wc = wait(NULL);
        printf("parent pid: %d\n", getpid());
        printf("parent wc: %d\n", wc);
    }
}