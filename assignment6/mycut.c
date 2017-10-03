#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]){
	// Gather the command line arguments (options included) and combine them in one string.
	// Create a command string that begins with "cut ", followed by the argument string above. 
	// Finally replace the hardwired "cut ...." in the following system call with your command string.  
	system("cut -d! -f3 emp.lst");
	
	return 0;
}
