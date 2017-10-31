#include <stdio.h>
#include <stdlib.h>
#include "mean.h"
#include "stddev.h"
#include "print_table.h"

#define MAX_ITEM 8

int main(int argc, char *argv[])
{
    double input[MAX_ITEM];
    double m, sd;
    int i;

    //ask for input and scan it into an int array
    printf("Please enter 8 numbers (any extra will be discarded):\n");
    for(i=0; i<MAX_ITEM; i++)
    {
        scanf("%lf", &input[i]);
    }

    //find mean and standard deviation
    m = mean(input, MAX_ITEM);
    sd = stddev(input, MAX_ITEM, m);
    printf("The mean is %.2lf\n",m);
    printf("The standard deviation is %.2lf\n\n",sd);
    
    //display table of difference between array items and their mean
    printTable(input, MAX_ITEM, m);
}