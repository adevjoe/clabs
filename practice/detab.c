#include <stdio.h>

#define TABNUM 8

void detab(int n);

/* 将制表符替换为空格 */
int main()
{
    int c, space;
    space = 0;
    while ((c = getchar()) != EOF)
    {
        space = space % TABNUM;
        if (c == '\t')
        {
            detab(TABNUM - space);
            space = 0;
        } else if (c == '\n')
        {
            space = 0;
            putchar(c);
        }else
        {
            space++;
            putchar(c);
        }
    }
    return 0;
}

void detab(int n)
{
    while(n){
        putchar(' ');
        n--;
    }
}