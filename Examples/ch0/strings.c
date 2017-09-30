#include <stdio.h>
#include <string.h>

int main(){
	char s1[]="Shatner";
	printf("sizeof(s1) = %ld\n", sizeof(s1)); //returns size of char array, which is string length plus one for '\0'
	printf("strlen(s1) = %ld\n", strlen(s1)); //returns actual string length

	char s2[20]="Shatner";
	printf("sizeof(s2) = %ld\n", sizeof(s2)); //takes up 8 of the 20 spots in s2 array
	printf("strlen(s2) = %ld\n", strlen(s2));

// We will come back and revisit the following part after learning pointers.
/*
	char *s3="Shatner";
	printf("sizeof(s3) = %i\n", sizeof(s3));
	printf("strlen(s3) = %i\n", strlen(s3));

	int d[]={1,2,3,4,5};
	int *p = d;
	printf("length of d = %i\n", sizeof(d)/sizeof(*d));
	printf("length of d = %i\n", sizeof(d)/sizeof(d[0]));
	printf("length of p = %lf\n", (double)sizeof(p)/sizeof(*p));
	printf("length of p = %lf\n", (double)sizeof(p)/sizeof(p[0]));
*/

	return(0);
}
