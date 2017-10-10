#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
	char output[100] = "";
	int i;
	
	strcat(output,"sort ");
	for(i=1; i<argc; i++) {
		strcat(output,argv[i]);
		strcat(output," ");
	}
	
	system(output);
	
	return 0;
}