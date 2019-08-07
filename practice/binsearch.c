#include <stdio.h>
#include <sys/time.h>

#include "binsearch.h"

int main()
{
    int a1, a2;
    struct timeval start1, start2, end1, end2;
    unsigned long timer1, timer2;
    int data[SIZE];
    for (int i = 0; i < SIZE; i++)
    {
        data[i] = i;
    }
    /* for (int i = 0; i < SIZE; i++)
    {
        printf("data[%d] address: %p\n", i, &data[i]);
    }*/
    gettimeofday(&start1, NULL);
    a1 = binsearch(22, data, SIZE);
    gettimeofday(&end1, NULL);
    timer1 = 1000000 * (end1.tv_sec - start1.tv_sec) + end1.tv_usec - start1.tv_usec;
    printf("binsearch cost: %ldus, result: %d\n", timer1, a1);
    gettimeofday(&start2, NULL);
    a2 = binsearch2(22, data, SIZE);
    gettimeofday(&end2, NULL);
    timer2 = 1000000 * (end2.tv_sec - start2.tv_sec) + end2.tv_usec - start2.tv_usec;
    printf("binsearch2 cost: %ldus, result: %d\n", timer2, a2);
}

/* binsearch: find x in v[0] <= v[1] <= ... <= v[n-1] */
int binsearch(int x, int v[], int n)
{
    int low, high, mid;
    low = 0;
    high = n - 1;
    while (low <= high)
    {
        mid = (low + high) / 2;
        // printf("v[%d] address: %p\n", mid, &v[mid]);
        if (x < v[mid])
            high = mid;
        else if (x > v[mid])
            low = mid;
        else /* found match */
            return mid;
    }
    return -1; /* no match */
}

// only one if
int binsearch2(int x, int v[], int n)
{
    int low, high, mid;
    low = 0;
    high = n - 1;
    mid = (low + high) / 2;
    while (high != low && v[mid] != x)
    {
        // printf("v[%d] address: %p\n", mid, &v[mid]);
        if (x < v[mid])
            high = mid;
        else
            low = mid;
        mid = (low + high) / 2;
    }
    if (v[mid] == x)
    {
        return mid;
    }
    return -1;
}