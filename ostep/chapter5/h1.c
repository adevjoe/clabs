#include <stdio.h>
#include <unistd.h>

int main() {
    int x = 100;
    int cp = fork();
    // copy on write
    if (cp == 0) {
        printf("Child: %d\n", x);
        x += 1;
        printf("Child: %d\n", x);
    } else {
        printf("Parent: %d\n", x);
        x += 2;
        printf("Parent: %d\n", x);
    }
    return 0;
}