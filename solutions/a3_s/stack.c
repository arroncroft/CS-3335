#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define STACK_SIZE 10
#define STACK_EMPTY -1

void push(char [], // input/ouput - the stack
	  char,	   // input - data being pushed onto the stack
	  int *,   // input/output - pointer to the top of stack
	  int);    // constant - maximum size of stack

char		   // output - data being popped out from the stack
     pop(char [],  // input/output - the stack
	 int *);   // input/output - pointer to top of stack

void push(char stack[],
	  char item,
	  int *top,
	  int max_size){

	// Your code here ...
	// Push item to the top of stack if it's not full. 
	// Update the top pointer s/t it points to the new top element on the stack.

	if(*top < max_size-1){
		++(*top);
		stack[*top] = item;
	}
}

char pop(char stack[],
	 int *top){

	// Your code here ...
	// Pop out the top item on the stack and return it if the stack is not emtpy.
	// Update the top pointer s/t it points to the new top element on the stack. 
	// 
	// Return STACK_EMPTY if the stack is empty. 	

	char item;
	if (*top >= 0){
		item = stack[*top];
		--(*top);
	}
	else{
		item = STACK_EMPTY;
	}

	return item;
}

int main(){
	char s[STACK_SIZE];
	int s_top = STACK_EMPTY; // The index of the top of the stack

	srand(time(NULL));

	// Your code here ...
	// (Using a loop) Keep pushing chars randomly picked between '!'(33) and '~'(126) to the stack
	// until it is full. 
	// Print each char before each pushing.

	char temp = 33; //'!'
	do{
		char c = temp+rand()%94;
		printf("Push: %c\n", c);
		push(s, c, &s_top, STACK_SIZE); 
	} while(s_top != STACK_SIZE-1);

	printf("-----------\n");

	// Your code here ...
	// (Using a loop) Keep popping out chars from the stack until it is empty
	// Print each char after each popping. 
	char t;
	do{
		t=pop(s, &s_top);
		if(t!=STACK_EMPTY)
			printf("Pop: %c\n", t);
	}while(t!=STACK_EMPTY);

	return 0;
}


