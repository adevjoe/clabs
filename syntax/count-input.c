#include <stdio.h>

#define IN 1  /* inside a word */
#define OUT 0 /* outside a word */

void countChar()
{
    long count;
    while (getchar() != EOF)
    {
        ++count;
    }
    printf("count: %ld", count);
}

void countLines()
{
    int c, nl;
    nl = 0;
    while ((c = getchar()) != EOF)
        if (c == '\n')
            ++nl;
    printf("%d\n", nl);
}

void countAll()
{
    int c, nl, ns, nt;
    nl = 0;
    ns = 0;
    nt = 0;
    while ((c = getchar()) != EOF)
        switch (c)
        {
        case ' ':
            ++ns;
            break;
        case '\n':
            ++nl;
            break;
        case '\t':
            ++nt;
            break;
        default:
            break;
        }
    printf("lines: %d, spaces: %d, tables: %d", nl, ns, nt);
}

void printOneSpace()
{
    int c;
    int spaces;
    char a;
    while ((c = getchar()) != EOF)
    {
        if (c == ' ')
        {
            spaces++;
        }
        else
        {
            if (spaces > 0)
            {
                printf("%c", ' ');
                spaces = 0;
            }
            a = c;
            printf("%c", a);
        }
    }
}

void printInsteadSymbol()
{
    int c;
    char a;
    while ((c = getchar()) != EOF)
    {
        switch (c)
        {
        case '\b':
            printf("\\b");
            break;
        case '\\':
            printf("\\\\");
            break;
        case '\t':
            printf("\\t");
            break;
        default:
            a = c;
            printf("%c", a);
            break;
        }
    }
}

void countWords()
{
    int c, nl, nw, nc, state;
    state = OUT;
    nl = nw = nc = 0;
    while ((c = getchar()) != EOF)
    {
        ++nc;
        if (c == '\n')
            ++nl;
        
        if (c == ' ' || c == '\n' || c == '\t')
            state = OUT;
        else if (state == OUT)
        {
            state = IN;
            ++nw;
        }
    }
    printf("lines:%d, words: %d, chars: %d\n", nl, nw, nc);
}

void printWordsEachLine()
{
    int c, nl, nw, nc, state;
    state = OUT;
    nl = nw = nc = 0;
    char a;
    while ((c = getchar()) != EOF)
    {
        ++nc;
        if (c == '\n')
            ++nl;
        
        if (c == ' ' || c == '\n' || c == '\t')
        {
            printf("\n");
            state = OUT;
        }
        else {
            if (state == OUT)
            {
                state = IN;
                ++nw;
            }
            a = c;
            printf("%c", c);
        }
    }
}

void printWordsLengthCharts()
{
    int c, nl, nw, nc, state;
    state = OUT;
    nl = nw = nc = 0;
    char a;
    int wordsLenght = 0;
    while ((c = getchar()) != EOF)
    {
        ++nc;
        if (c == '\n')
            ++nl;
        
        if (c == ' ' || c == '\n' || c == '\t')
        {
            state = OUT;
            printf(":\t ");
            for (int i = 0; i < wordsLenght; i++)
            {
                printf("#");
            }
            printf("\n");
            wordsLenght = 0;
        }
        else {
            wordsLenght++;
            a = c;
            printf("%c", a);
            if (state == OUT)
            {
                state = IN;
                ++nw;
            }
        }
    }
}

int main()
{
    // countChar();
    // countLines();
    // countAll();
    // printOneSpace();
    // printInsteadSymbol();
    // countWords();
    // printWordsEachLine();
    printWordsLengthCharts();
    return 0;
}