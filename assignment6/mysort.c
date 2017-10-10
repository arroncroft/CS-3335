#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main(int argc, char *argv[]){
	// Gather the command line arguments (options included) and combine them in one string.
	// Create a command string that begins with "sort ", followed by the argument string above. 
	// Finally replace the hardwired "sort ...." in the following system call with your command string.  
	//system("sort");
	
	char ch;
	int n = 0;
	char output[100] = "";

	while ((ch = getopt(argc, argv, "n")) != EOF)
	{
		switch (ch)
		{
		case 'n':
			n = 1;
			break;
		default:
			fprintf(stderr, "unknown option: '%s'\n", optarg);
			return 1;
		}
	}

	argc -= optind;
	argv += optind;
	
	strcpy(output,"sort ");
	if (n) 
	{
		strcat(output,"-n ");	
	}
	
	if (argv[0])
	{
		strcat(output,*argv);
	}
	
	system(output);
	
	return 0;
}
