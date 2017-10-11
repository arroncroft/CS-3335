#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int main(int argc, char *argv[])
{
	// Get the options (-c, -d, -u, some combinations of them, or none at all)
	// ... ...

	// Figure out whether the input is comng from a file
	// whose name is provided as a command line argument like
	// 	myuniq -c -d sorteddepts.lst
	// or from the stdin like
	// 	mycut .... | mysort ... | myuniq -c -d
	// ... ...

	// You may assume the input data are all sorted.
	// Read and record two lines (if any) from input and compare them.
	// Let's call them prev and curr.
	// If they are the same, update the number of repeats;
	// If they are different, output the prev according the options (-c, -d, or -u)
	// Keey doing this until hitting the end of the input.
	// ... ...

	char ch;
	int c = 0;
	int d = 0;
	int u = 0;
	int i;
	char prev[300];
	char current[300];
	int count = 1;
	FILE *data;

	while ((ch = getopt(argc, argv, "cdu")) != EOF)
	{
		switch (ch)
		{
		case 'c': //count number of times the line is repeated
			c = 1;
			break;
		case 'd': //only show repeated lines
			if (u != 1)
				d = 1;
			else
				fprintf(stderr, "invalid option: -d -u can not co-exist for uniq\n");
			break;
		case 'u': //only show non-repeated lines
			if (d != 1)
				u = 1;
			else
				fprintf(stderr, "invalid option: -d -u can not co-exist for uniq\n");
			break;
		default:
			fprintf(stderr, "unknown option: '%s'\n", optarg);
			return 1;
		}
	}

	argc -= optind;
	argv += optind;

	switch (argc)
	{
	case 0:
		data = stdin;
		break;
	case 1:
		data = fopen(argv[0], "r");
		break;
	default:
		printf("myuniq [-c | -du] [input [output]]\n");
	}

	fgets(prev, 200, data);
	while (fgets(current, 200, data) != NULL)
	{
		if (strcmp(prev, current) == 0)
			count++;
		else
		{
			if (c)
				printf("%d ", count);
			if (d)
			{
				if (count > 1)
					printf("%s", prev);
				else
					printf("\n");
			}
			if (u)
				printf("\n");
			count = 1;
			strcpy(prev, current);
		}
	}

	if (count != 0)
	{
		if (c)
			printf("%d ", count);
		if (d)
		{
			if (count > 1)
				printf("%s", prev);
		}
		if (u)
		{
			if (count == 1)
				printf("%s", prev);
		}
	}
	printf("\n");

	return 0;
}
