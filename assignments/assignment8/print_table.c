#include <stdio.h>
#include <stdlib.h>
#include "print_table.h"

void printTable(double input[], int size, double mean)
{
	int i;
	
	printf("Table of diff between data items and mean\n");
	printf("-----------------------------------------\n");
	printf("Index\t\tItem\t\tDiff\n");
	
	for(i=0; i<size; i++)
	{
		printf("%d\t\t%.2lf\t\t%.2lf\n", i, input[i], input[i] - mean);
	}
}