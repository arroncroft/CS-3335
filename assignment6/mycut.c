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
	char output[100] = "";

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

	//create a string to output to the command line
	strcpy(output,"cut ");
	if(d[0]) {
		strcat(output,"-d");
		strcat(output,d);
		strcat(output," ");
	}
	if(f[0]) {
		strcat(output,"-f");
		strcat(output,f);
		strcat(output," ");
	}
	if(argv[0]) {
		strcat(output,*argv);
	}

	//test loop 
	/*
	int i;
	for(i=0;i<sizeof(output)/sizeof(char);i++){
		printf("%c",output[i]);
	}
	printf("\n");
	*/

	//output string to command line
	system(output);

	return 0;
}