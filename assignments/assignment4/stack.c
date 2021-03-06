#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define STACK_SIZE 10

#define STACK_FULL -2
#define STACK_EMPTY -1
#define NORMAL 0

int myerror = NORMAL;

void push(double[],  // input/ouput - the stack
	  double,    // input - data being pushed onto the stack
	  double **, // input/output - pointer to pointer to the top of stack
	  int);      // constant - maximum capacity of stack

double pop(double[],   // output - data being popped out from the stack
	   double **); // input/output - the stack
		       // input/output - pointer to pointer to top of stack

void push(double stack[],
	  double item,
	  double **top,
	  int max_size)
{

	// Your code here...
	if (*(int *)top < max_size) //check to see if stack is full
	{
		myerror = NORMAL;
		stack[*(int *)top] = item;
 		(*(int *)top)++;
	}
	else {
		myerror = STACK_FULL;
		printf("Stack is full!\n");
	}
	// my code ends
}

double pop(double stack[],
	   double **top)
{

	// Your code here...
	double popped;
	if (*(int *)top > 0) {
		myerror = NORMAL;
		(*(int *)top)--;
		popped = stack[*(int *)top];
		stack[*(int *)top] = (int)NULL;
		return popped;
	}
	else {
		myerror = STACK_EMPTY;
		return 0.0;
	}
	// my code ends

	return 0.0;
}

int main()
{
	double s[STACK_SIZE];
	double *s_top = NULL;
	srand(time(NULL));

	// Keep pushing doubles equivalent to chars randomly picked between '!'(33) and '~'(126)
	// to the stack until it is full.
	// Print each double before each pushing.

	//my code begins
	double random;
	int i;
	while (myerror == NORMAL) {
		random = rand() % 93 + 33;
		printf("%.2f\n", random);
		push(s, random, &s_top, STACK_SIZE);
	}
	printf("-----------\n");
	//my code ends

	// Keep popping out doubles from the stack until it is empty
	// Print each double after each popping.

	//my code
	do {
		printf("%.2f\n", pop(s, &s_top));
	} while (myerror == NORMAL);
	//my code ends

	return 0;
}
