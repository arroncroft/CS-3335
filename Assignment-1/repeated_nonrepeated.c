#include <stdio.h>

int main(){
	// Change the elements in the following array
	// to test your program
	int digits[]={2,0,38,2,3,1,3};
	int i;

	printf("In the array of ");	
	for (i=0; i<sizeof(digits)/sizeof(int); i++)
		printf("%d ", digits[i]);
	printf("\n");	

	// Your code here...

	return 0;
}
