#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
	// Gather the command line arguments (options included) and combine them in one string.
	// Create a command string that begins with "cut ", followed by the argument string above.
	// Finally replace the hardwired "cut ...." in the following system call with your command string.
	// system("cut -d! -f3 emp.lst");

	char ch;
	char *d = "";
	char *f = "";
	int count = 0;

	while ((ch = getopt(argc, argv, "d:f:")) != EOF)
	{
		switch (ch)
		{
		case 'd':
			d = optarg;
			break;
		case 'f':
			f = optarg;
			break;
		default:
			fprintf(stderr, "unknown option: '%s'\n", optarg);
			return 1;
		}
	}

	argc -= optind;
	argv += optind;

	if(d[0])
		printf("testing\n");
	if(f[0])
		printf("testing 2\n");

	return 0;
}
