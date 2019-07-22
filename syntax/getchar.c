#include <stdio.h>

void printv1()
{
    int c;
    c = getchar();
    while (c != EOF)
    {
        putchar(c);
        c = getchar();
    }
}

void printv2()
{
    int c;
    while ((c = getchar()) != EOF)
    {
        putchar(c);
    }
}

void testGetChar()
{
    printf("%d", getchar() != EOF);
}

void printEOF()
{
    printf("EOF: %d", EOF);
}

int main()
{
    printv1();
    // printv2();
    // testGetChar();
    // printEOF();
    return 0;
}