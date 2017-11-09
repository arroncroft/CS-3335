#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "stddev.h"

double stddev(double input[], int size, double mean)
{
    double stddev, sum;
 	int i;
    
    for(i = 0; i < size; i++)
    {
    	sum = sum + pow(input[i],2);
    }
    
    stddev = sum / size;
    stddev -= pow(mean,2);
    stddev = sqrt(stddev);
	
    return stddev;
}