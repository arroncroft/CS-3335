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
char tokens[100];
double answer;

void push(double[],  // input/ouput - the stack
          double,    // input - data being pushed onto the stack
          double **, // input/output - pointer to pointer to the top of stack
          int);      // constant - maximum capacity of stack

double pop(double[],   // output - data being popped out from the stack
           double **); // input/output - the stack
                       // input/output - pointer to pointer to top of stack

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

int main()
{
    double s[STACK_SIZE];
    double *s_top = NULL;

    printf("**************** Calculator *****************\n");
    printf("6 working operators: +, -, *, /, sin, and log\n");
    printf("Please input your problems to calculate\n");
    printf("*********************************************\n");
    fgets(input, sizeof(input), stdin);
    input[strlen(input) - 1] = '\0';
    //test
    char delim[]=" ";
    tokens[0] = strtok(input, delim);
    //test end
    printf("%s\t\t%s\n", "Input:", input);
    printf("%s\t\t%f\n", "Answer:", answer);
    printf("*********************************************\n");
}