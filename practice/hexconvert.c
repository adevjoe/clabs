#include <stdio.h>
#include <string.h>
#include <math.h>

int htos(char s[8]);
int getNumBy16Hex(char s);

int main()
{
    char s[8];
    scanf("%s", s);
    printf("%d", htos(s));
    return 0;
}

int htos(char s[8])
{
    int i, num, n, len;
    i = num = 0;
    len = strlen(s);
    while (s[i] != '\0')
    {
        if ((n = getNumBy16Hex(s[i])) > 0)
        {
            num += n * (int) pow(16, len - i - 1);
        }
        i++;
    }
    return num;
}

int getNumBy16Hex(char s)
{
    if (s >= '0' && s <= '9')
    {
        return s - 48;
    }
    if (s >= 'a' && s <= 'f')
    {
        return s - 87;
    }
    if (s >= 'A' && s <= 'F')
    {
        return s - 55;
    }
    return 0;
}