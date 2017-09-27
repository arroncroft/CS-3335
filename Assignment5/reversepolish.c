//reversepolish.c
//6 working operators:
//+, -, *, /, sin, log

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define STACK_SIZE 10
#define STACK_FULL -2
#define STACK_EMPTY -1
#define NORMAL 0

int myerror = NORMAL;
char input[100];
double answer;

void push(double[],  // input/ouput - the stack
          double,    // input - data being pushed onto the stack
          double **, // input/output - pointer to pointer to the top of stack
          int);      // constant - maximum capacity of stack

double pop(double[],   // output - data being popped out from the stack
           double **); // input/output - the stack
                       // input/output - pointer to pointer to top of stack
                      
double degreesToRadians(double degrees);

void push(double stack[], double item,
          double **top, int max_size)
{
    if (*top < stack + (max_size - 1))
    {
        if (*top == NULL)
            *top = stack;
        else
            (*top)++;
        **top = item;
        myerror = NORMAL;
    }
    else
        myerror = STACK_FULL;
}

double pop(double stack[], double **top)
{
    double item;
    if (*top != NULL)
    {
        item = **top;
        if (*top == stack)
            *top = NULL;
        else
            (*top)--;
        myerror = NORMAL;
    }
    else
    {
        item = STACK_EMPTY; // not used when myerror is not NORMAL
        myerror = STACK_EMPTY;
    }
    return item;
}

double degreesToRadians(double degrees) {
	return (degrees * M_PI / 180);
}

int main()
{
    double s[STACK_SIZE];
    double *s_top = NULL;
    char *c;
    char *endptr;
    double temp;
    int i;
    int loop;

    printf("**************** Calculator *****************\n");
    printf("6 working operators: +, -, *, /, sin, and log\n");
    printf("Please input your problems to calculate\n");
    printf("*********************************************\n");
    while (1) {
	    fgets(input, sizeof(input), stdin);
	    input[strlen(input) - 1] = '\0';
	    c = strtok(input, " ");
	    while (c != NULL)
	    {
	        temp = strtod(c, &endptr);
	        if (c != endptr && *endptr == '\0') {
	            push(s, temp, &s_top, STACK_SIZE);
	    	}
	        else if (c == endptr)
	        {
	        	if (strcmp(endptr,"-") == 0) {
	        		double rightOp = pop(s, &s_top);
	        		answer = (pop(s, &s_top)) - rightOp;
	        		push(s, answer, &s_top, STACK_SIZE);
	    		}
	           	else if (strcmp(endptr,"+") == 0) {
	           		double rightOp = pop(s, &s_top);
	           		answer = (pop(s, &s_top)) + rightOp;
	           		push(s, answer, &s_top, STACK_SIZE);
	       		}
	           	else if (strcmp(endptr,"/") == 0) {
	           		double rightOp = pop(s, &s_top);
	           		answer = (pop(s, &s_top)) / rightOp;
	 	           	push(s, answer, &s_top, STACK_SIZE);
	       		}
	           	else if (strcmp(endptr,"*") == 0) {
	           		double rightOp = pop(s, &s_top);
	           		answer = (pop(s, &s_top)) * rightOp;
	           		push(s, answer, &s_top, STACK_SIZE);
	       		}
	       		else if (strcmp(endptr,"log") == 0) {
	           		double operand = pop(s, &s_top);
	           		answer = log(operand);
	           		push(s, answer, &s_top, STACK_SIZE);
	       		}
	       		else if (strcmp(endptr,"sin") == 0) {
	           		double angle = pop(s, &s_top);
	           		answer = sin(degreesToRadians(angle));
	           		push(s, answer, &s_top, STACK_SIZE);
	       		}
	        }
	        c = strtok(NULL, " ");
	    }
	    printf("%s\t\t%g\n", "Answer:", answer);
	    printf("*********************************************\n");
	    if (loop == EOF)
	    	break;
	}
}