#include <stdio.h>
#include <stdlib.h>
#include "mean.h"

double mean(double input[], int size)
{
    double sum;
    int i;
    
    for(i = 0; i < size; i++)
    {
    	sum = sum + input[i];
    }
    
    return sum/size;
}