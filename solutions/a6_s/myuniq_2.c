#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]){
	int len;

	int i=0;
	for (i=1; i<argc; i++){
		len = len + strlen(argv[i]) + 1;
	}

	char argvs[len+5];
	argvs[0]='\0';
	sprintf(argvs, "%s", "uniq ");	
	for(i=1; i<argc; i++){
		strcat(argvs, argv[i]);
		if(i!=argc-1){
			strcat(argvs, " ");
		}
	}
	// printf("%s", argvs);
	system(argvs);
	
	return 0;
}
