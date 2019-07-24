#include <stdio.h>

#define TABNUM 8

void entab(int n, int last);

int main()
{
    int c, space, last;
    space = 0;
    last = 0;
    while ((c = getchar()) != EOF)
    {
        if (c == ' ')
        {
            space++;
        }else if (space > 0)
        {
            last = last % TABNUM;
            while (space)
            {
                int remain = TABNUM - last;
                if (space >= TABNUM)
                {
                    putchar('\t');
                    space = space - remain;
                    last = 0;
                }else
                {
                    putchar(' ');
                    space--;
                    last++;
                }
            }
            last = (last + 1) % TABNUM;
            putchar(c);
        }else
        {
            last = (last + 1) % TABNUM;
            putchar(c);
        }
    }
    
    return 0;
}