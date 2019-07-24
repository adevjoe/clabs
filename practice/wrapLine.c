#include <stdio.h>
#include <string.h>

#define LINELIMIT 80

void printTmp(char tmp[80], int size);

int main()
{
    int c, pos, i;
    i = 0;
    pos = 1;
    char tmp[80] = "";
    while ((c = getchar()) != EOF)
    {
        if (c == ' ' || c == '\t')
        {
            if (pos <= LINELIMIT)
            {
                printTmp(tmp, i - 1);
                putchar(c);
            }
            else
            {
                putchar('\n');
                printTmp(tmp, i - 1);
                putchar(c);
                pos = i;
            }
            strcpy(tmp, "");
            i = 0;
        }
        else
        {
            tmp[i] = c;
            i++;
        }
        pos++;
    }
    if (pos <= LINELIMIT)
    {
        printTmp(tmp, i - 1);
    }
    else
    {
        putchar('\n');
        printTmp(tmp, i - 1);
    }
    return 0;
}

void printTmp(char tmp[80], int size)
{
    int i = 0;
    while (size >= 0)
    {
        putchar(tmp[i]);
        i++;
        size--;
    }
}