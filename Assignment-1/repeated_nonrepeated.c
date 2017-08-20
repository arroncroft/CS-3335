#include <stdio.h>
#include <stdbool.h>

int main(){
	
	// Change the elements in the following array
	// to test your program
	int digits[]={2,0,38,2,3,1,3};
	int i;
	bool found = false;

	printf("In the array of: ");	
	for (i=0; i<sizeof(digits)/sizeof(int); i++)
		printf("%d ", digits[i]);
	printf("\n\n");	
	
	//first non-repeated digit
	for (i=0; i<sizeof(digits)/sizeof(int); i++) {
		for (int j=i+1; j<sizeof(digits)/sizeof(int); j++) {
			found = false;
			if (digits[i] == digits[j]) {
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
	
	//last non-repeated digit
	for (i=(sizeof(digits)/sizeof(int))-1; i>=0; i--) {
		for (int j=i-1; j>=0; j--) {
			found = false;
			if (digits[i] == digits[j]) {
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

	//first repeated digit
	found = false;
	for (i=0; i<sizeof(digits)/sizeof(int); i++) {
		for (int j=i+1; j<sizeof(digits)/sizeof(int); j++) {
			found = false;
			if (digits[i] == digits[j]){
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

	//last repeated digit
	for (i=(sizeof(digits)/sizeof(int))-1; i>=0; i--) {
		for (int j=i-1; j>=0; j--) {
			found = false;
			if (digits[i] == digits[j]){
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

	return 0;
}
