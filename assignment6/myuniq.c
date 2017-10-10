#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int main(int argc, char *argv[]){
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

	while ((ch = getopt(argc, argv, "cdu")) != EOF) {
		switch (ch) {
			case 'c':
				c = 1;
				break;
			case 'd':
				d = 1;
				break;
			case 'u':
				u = 1;
				break;
			default:
				fprintf(stderr, "unknown option: '%s'\n", optarg);
				return 1;
		}
	}

	return 0;
}
