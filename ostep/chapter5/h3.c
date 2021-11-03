#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <signal.h>

void sig_handler(int signo)
{
    if (signo == SIGTERM)
        printf("goodbye\n");
}

int main() {
    int pid = fork();
    if (pid == 0) {
        printf("hello\n");
        kill(getppid(), SIGTERM);
        exit(0);
    } else {
        signal(SIGTERM, sig_handler);
        printf("debug: wait signal\n");
        pause();
    }
    return 0;
}