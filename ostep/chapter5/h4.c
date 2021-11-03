#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    int pid = fork();
    if (pid == 0) {
        char *args[] = {"ls", "-l", NULL};
        execl(args[0], args[0], args[1], args[2], NULL);
        execlp(args[0], args[0], args[1], args[2], NULL);
        execle(args[0], args[0], args[1], args[2], NULL, NULL);
        execv(args[0], args);
        execvp(args[0], args); // 有输出
        execve(args[0], args, NULL);
    } else {
        wait(NULL);
    }
    return 0;
}