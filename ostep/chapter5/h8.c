#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>

int main() {
    pid_t pids[2];
    int fd[2];
    char greeting[] = "Hello, world!\n";
    char readbuffer[BUFSIZ];
    pipe(fd);
    pids[0] = fork();
    if (pids[0] == 0) {
        close(fd[0]);
        dup2(fd[1], STDOUT_FILENO);
        // write(fd[1], greeting, sizeof(greeting));
        printf("I am child process.");
        exit(0);
    } else {
        waitpid(pids[0], NULL, 0);
        pids[1] = fork();
        if (pids[1] == 0) {
            close(fd[1]);
            dup2(fd[0], STDIN_FILENO);
            // read(fd[0], readbuffer, sizeof(readbuffer));
            read(STDIN_FILENO, readbuffer, sizeof(readbuffer));
            printf("I am child process %d, Received string: %s\n",getpid(), readbuffer);
            exit(0);
        } else {
            waitpid(pids[1], NULL, 0);
        }
    }
    return 0;
}