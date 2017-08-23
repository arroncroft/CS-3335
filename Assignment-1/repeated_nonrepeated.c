#include <stdio.h>
#include <stdbool.h>

int main() {
	
	int digits[] = {2,0,38,2,3,1,3}; //test some repeated and some not
	//int digits[] = {2,25,0,26,30,13,25,30,13,0}; //different version of first test
	//int digits[] = {26,25,0,26,30,13,25,30,13,0}; //test all repeated
	//int digits[] = {1,2,0,4}; //test none repeated
	int digitsCheck[100] = {0};
	int i;
	bool found = false;
	
	//print digits array
	printf("In the array of: ");	
	for (i=0; i<sizeof(digits)/sizeof(int); i++)
		printf("%d ", digits[i]);
	printf("\n\n");	
	
	//update digitsCheck
	for (i=0; i<sizeof(digits)/sizeof(int); i++) {
		digitsCheck[digits[i]]++;
	}
	
	//find first and last non-repeated digit
	for (i=0; i<sizeof(digits)/sizeof(int); i++) {
		if (digitsCheck[digits[i]] == 1){
			printf("The first non-repeated digit is %d.\n",digits[i]);
			found = true;
			break;
		}
	}
	if (found == false) {
		printf("There is no non-repeated digit.\n");
	}
	else {
		found = false;
		for (i=sizeof(digits)/sizeof(int)-1; i>=0; i--) {
			if (digitsCheck[digits[i]] == 1){
				printf("The last non-repeated digit is %d.\n",digits[i]);
				found = true;
				break;
			}
		}
	}

	//find first and last repeated digit
	found = false;
	for (i=0; i<sizeof(digits)/sizeof(int); i++) {
		if (digitsCheck[digits[i]] > 1){
			printf("The first repeated digit is %d.\n",digits[i]);
			found = true;
			break;
		}
	}
	if (found == false) {
		printf("There is no repeated digit.\n");
	}
	else {
		found = false;
		for (i=sizeof(digits)/sizeof(int)-1; i>=0; i--) {
			if (digitsCheck[digits[i]] > 1){
				printf("The last repeated digit is %d.\n",digits[i]);
				found = true;
				break;
			}
		}
	}

	return 0;
}
