#include <stdio.h>
#include <stdbool.h>

int main() {
	
	int digits[] = {2,0,38,2,3,1,3}; //test some repeated and some not
	//int digits[] = {3,1,1,5,3,5}; //test all repeated
	//int digits[] = {1,2,3,4,5,6}; //test none repeated
	int i;
	int j;
	bool found = false;
	
	//print digits array
	printf("In the array of: ");	
	for (i=0; i<sizeof(digits)/sizeof(int); i++)
		printf("%d ", digits[i]);
	printf("\n\n");	
	
	//first non-repeated digit//
	for (i=0; i<sizeof(digits)/sizeof(int); i++) {
		for (j=0; j<sizeof(digits)/sizeof(int); j++) {
			found = false;
			if (i != j && digits[i] == digits[j]) {
				found = true;
				break;
			}
		}
		if (found == false) {
			printf("The first non-repeated digit is %d.", digits[i]);
			break;
		}
	}
	if (found == true) {
		printf("There is no non-repeated digit.");
		}
	printf("\n");
	
	//last non-repeated digit//
	if (found == false) {
		for (i=(sizeof(digits)/sizeof(int))-1; i>=0; i--) {
			for (j=(sizeof(digits)/sizeof(int))-1; j>=0; j--) {
				found = false;
				if (i != j && digits[i] == digits[j]) {
					found = true;
					break;
				}
			}
			if (found == false) {
				printf("The last non-repeated digit is %d.", digits[i]);
				break;
			}
		}
		if (found == true) {
			printf("There is no non-repeated digit.");
		}
		printf("\n");
	}

	//first repeated digit//
	found = false;
	for (i=0; i<sizeof(digits)/sizeof(int); i++) {
		for (j=0; j<sizeof(digits)/sizeof(int); j++) {
			found = false;
			if (i != j && digits[i] == digits[j]){
				found = true;
				break;
			}
		}
		if (found == true) {
			printf("The first repeated digit is %d.", digits[i]);
		}
		else {
			printf("There is no repeated digit.");
		}
		break;
	}
	printf("\n");

	//last repeated digit//
	if (found == true) {
		for (i=(sizeof(digits)/sizeof(int))-1; i>=0; i--) {
			for (j=(sizeof(digits)/sizeof(int))-1; j>=0; j--) {
				found = false;
				if (i != j && digits[i] == digits[j]){
					found = true;
					break;
				}
			}
			if (found == true) {
				printf("The last repeated digit is %d.", digits[i]);
			}
			else {
				printf("There is no repeated digit.");
			}
			break;
		}
		printf("\n");
	}

	return 0;
}
