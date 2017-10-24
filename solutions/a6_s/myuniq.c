#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

void show(FILE *ofp, char *str, int repeats, int cflag, int rflag, int uflag);

void show(FILE *ofp, char *str, int repeats, int cflag, int rflag, int uflag){
	if ((rflag && repeats) || (uflag && !repeats)){
		if (cflag)
			fprintf(ofp, "%7d ", repeats + 1);
		fprintf(ofp, "%s\n", str);
	}
}

int main(int argc, char *argv[]){
	int count = 0;
	int repeated = 0;
	int uniq = 0;

	char ch;

	while( (ch=getopt(argc, argv, "cdu"))!=EOF ){
		switch(ch){
			case 'c':
				count = 1;
				break;
			case 'd':
				repeated = 1;
				break;
			case 'u':
				uniq = 1;
				break;
			default:
				fprintf(stderr, "unknown option: '%s'\n", optarg);
				return 1;
		}
	}

	if (repeated && uniq){
		fprintf(stderr, "invalid option: -d -u can not co-exist for uniq\n");
		return 1;	
	}

	if (!repeated && !uniq)
		repeated = uniq = 1;

	argc -= optind;
	argv += optind;

	FILE *ifp, *ofp;

	switch(argc) {
		case 0:
			ifp = stdin;
			ofp = stdout;
			break;
		case 1:
			if(!(ifp = fopen(argv[0], "r"))) {
				fprintf(stderr, "Can't open the file.\n");
				return 1;
			}

			ofp = stdout;
			break;
		default:
			fprintf(stderr, "usage: myuniq [-c] [-d|u] [input]");
                        return 1;	
	}


	char tline[200];
 	char pline[200];
	char *thisline = tline, *prevline=pline, *temp;
	int repeats = 0;

	if(fscanf(ifp, "%199[^\n]\n", prevline)!=1)
		return 1;

	while (fscanf(ifp, "%199[^\n]\n", thisline)==1){
		if (strcmp(prevline, thisline)) {
			show(ofp, prevline, repeats, count, repeated, uniq);
			temp = prevline;
			prevline = thisline;
			thisline = temp;
			repeats = 0;
		} else
			++repeats;	
	}
	show(ofp, prevline, repeats, count, repeated, uniq);

	fclose(ifp);
	fclose(ofp);
	return 0;
}
