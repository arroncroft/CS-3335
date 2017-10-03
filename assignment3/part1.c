#include <stdio.h>
#include <stdlib.h>

#define SIZE 100

int main()
{
    char a[SIZE], *p = a;
    int i;

    for (i = 0; i < SIZE; i++)
        a[i] = i;

    printf( "% d\n", *(p + 3));
    printf( "% d\n", *(char *)((int *)p + 3));
    printf( "% d\n", *(char *)((double *)p + 3));
    printf( "% d\n", *(char *)((long double *)p + 3));

    return 0;
}