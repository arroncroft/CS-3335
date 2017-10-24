#include <stdio.h>
#include <string.h>

int main(){
	//int digits[]={2,25,0,26,30,13,25,30,13,0};
	int digits[]={26,25,0,26,30,13,25,30,13,0};
//	int digits[]={1,21,0,21,4,21};
	//int digits[]={1,2,0,4};
	int i;

	printf("In the array of ");	
	for (i=0; i<sizeof(digits)/sizeof(int); i++)
		printf("%d ", digits[i]);
	printf("\n");	

	int seen[100]={0};

	for (i=0; i<sizeof(digits)/sizeof(int); i++){
		int temp = digits[i];
		if (seen[temp]==0){
			seen[temp]=1;
		}
		else if (seen[temp]==1){
			seen[temp]=2;
		}
	}
	/*
	  or (i=0; i<sizeof(seen)/sizeof(int); i++){
		if(seen[i]!=0)
			printf("seen[%d]=%d\t",i,seen[i]);
	}
	*/
	printf("\n");

	int first_nonrepeat = -1;
	int first_repeat = -1;

	for (i=0; i<sizeof(digits)/sizeof(int); i++){
		if(seen[digits[i]]==1){
			if (first_nonrepeat==-1)
				first_nonrepeat=digits[i];
			if (first_repeat!=-1)
				break; 
		}
		if(seen[digits[i]]==2){
			if (first_repeat==-1)
				first_repeat=digits[i];
			if (first_nonrepeat!=-1)
				break; 
		}
	}

	int last_nonrepeat = -1;
	int last_repeat = -1;
	for (i=sizeof(digits)/sizeof(int)-1; i>=0; i--){
		if(seen[digits[i]]==1){
			if (last_nonrepeat==-1)
				last_nonrepeat=digits[i];
			if (last_repeat!=-1)
				break; 
		}
		if(seen[digits[i]]==2){
			if (last_repeat==-1)
				last_repeat=digits[i];
			if (last_nonrepeat!=-1)
				break; 
		}
	}

	if (first_nonrepeat==-1)
		printf("There isn't any non-repeated digit.\n");
	else{
		printf("The first non-repeated digit is %d.\n", first_nonrepeat);
		printf("The last non-repeated digit is %d.\n", last_nonrepeat);
	}

	if (first_repeat==-1)
		printf("There isn't any repeated digit.\n");
	else{
		printf("The first repeated digit is %d.\n", first_repeat);
		printf("The last repeated digit is %d.\n", last_repeat);
	}

	return 0;
}
