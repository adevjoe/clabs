/*
a-z to abc....xyz
0-9 to 0123456789
-a-z to -abc...xyz
*/
#include <stdio.h>

#define LOWER_LETTER 1
#define CAPITAL_LETTER 2
#define NUMBER 3

int expand(char s1[], char s2[]);

int main()
{
    char s1[100] = "-a-z 0-9 a-d-f -0-2 some text 1-1 WITH CAPITALS! "
                   "0-0 5-3 - A-z A-Z a-0";
    /* output
    -abcdefghijklmnopqrstuvwxyz 0123456789 abcdef 
    -012 some text 1 WITH CAPITALS! 0 5-3 - A-z ABCDEFGHIJKLMNOPQRSTUVWXYZ a-0
    */
    char s2[1000];
    expand(s1, s2);
    printf("s1: %s\n", s1);
    printf("s2: %s", s2);
    return 0;
}

int expand(char s1[], char s2[])
{
    int pos = 0;
    char pre_char = 0;
    int skip = 0;
    for (int i = 0; s1[i] != '\0'; i++)
    {
        if (pre_char != 0 && s1[i] == '-')
        {
            skip = 1;
            continue;
        }
        else if (skip == 1 && s1[i] >= pre_char && ((s1[i] <= 'z' && s1[i] - pre_char <= 25)
        || (s1[i] <= 'Z' && s1[i] - pre_char <= 25) || (s1[i] <= '9' && s1[i] - pre_char <= 9)))
        {
            if (s1[i] == pre_char)
            {
                skip = 0;
                continue;
            }
            int count = s1[i] - pre_char;
            for (int j = 0; j < count; j++)
            {
                s2[pos] = pre_char + 1;
                pre_char++;
                pos++;
            }
            skip = 0;
            pre_char = s1[i];
            continue;
        }
        else if ((s1[i] >= 'a' && s1[i] <= 'z') || (s1[i] >= 'A' && s1[i] <= 'Z') ||
                 (s1[i] >= '0' && s1[i] <= '9'))
        {
            pre_char = s1[i];
        }
        else
        {
            skip = 0;
            pre_char = 0;
        }
        if (skip == 1)
        {
            s2[pos] = '-';
            pos++;
        }
        s2[pos] = s1[i];
        pos++;
    }
    return 0;
}