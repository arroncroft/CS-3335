#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define STACK_SIZE 10
#define STACK_EMPTY -1

void push(char [], // input/ouput - the stack
	  char,	   // input - data being pushed onto the stack
	  int *,   // input/output - pointer to the ***index*** of the top of stack
	  int);    // constant - maximum size of stack

char		   // output - data being popped out from the stack
     pop(char [],  // input/output - the stack
	 int *);   // input/output - pointer to the ***index*** of the top of stack

void push(char stack[],
	  char item,
	  int *top,
	  int max_size){

	// Your code here ...
	// Push item to the top of stack if it's not full. 
	// Update the top pointer s/t it points to the index of the new top element on the stack.

	//my code
	if (*top < STACK_SIZE - 1) { //if stack is not full
		stack[*top + 1] = item; // push to top of stack
		*top = *top + 1; //set pointer to top of stack
	}
	//my code ends
}

char pop(char stack[],
	 int *top){

	// Your code here ...
	// Pop out the top item on the stack and return it if the stack is not emtpy.
	// Update the top pointer s/t it points to the index of the new top element on the stack. 
	// 
	// Return STACK_EMPTY if the stack is empty. 	

	//my code
	if (*top > STACK_EMPTY) {
		char popped = stack[*top];
		stack[*top] = ' ';
		*top = *top - 1;
		return popped;
	}
	//my code ends

	return STACK_EMPTY;
}

int main(){
	char s[STACK_SIZE];
	int s_top = STACK_EMPTY; // The ***index*** of the top of the stack
	int i;

	srand(time(NULL));

	// Your code here ...
	// (Using a loop) Keep pushing chars randomly picked between '!'(33) and '~'(126) to the stack
	// until it is full. You will find the function rand() useful here. In case you are not familiar
	// with it, man it.
	// Print each char before each pushing.

	//my code
	srand ( time(0) );	
	char random = rand() % 93 + 33;
	for (i = 0; i < STACK_SIZE; i++) {
		random = rand() % 93 + 33;
		printf("%c\n", random);
		push(s, random, &s_top, STACK_SIZE);
	}
	//my code ends

	printf("-----------\n");

	// Your code here ...
	// (Using a loop) Keep popping out chars from the stack until it is empty
	// Print each char after each popping. 

	//my code
	for (i = 0; i < STACK_SIZE; i++) {
		printf("%c\n", pop(s, &s_top));
	}
	//my code ends

	return 0;
}
