#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "mean.c"
#include "stddev.c"

#define MAX_ITEM 8

int main(int argc, char *argv[])
{
    double input[MAX_ITEM];
    double mean, stddev;
    int i;

    //ask for input and scan it into an int array
    printf("Please enter 8 numbers (any extra will be discarded):\n");
    for(i=0; i<MAX_ITEM; i++){
        scanf("%lf", &input[i]);
    }

    //find mean and standard deviation
    mean = mean(input);
    stddev = stddev(input);
}