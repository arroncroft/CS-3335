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
char infix[100];
char postfix[100];
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
    fgets(infix, sizeof(infix), stdin);
    infix[strlen(infix) - 1] = '\0';
    printf("%s\t\t%s\n", "Infix:", infix);
    //next: convert to tokens and add to tokens array
    char *c;
    c = strtok(infix, " ");
    while (c != NULL)
    {
        //printf("%s %s\n","Token:",c);
        //test
        char *endptr;
        double temp = strtod(c, &endptr);
        if (c != endptr && *endptr == '\0')
            printf("%lg ", temp);
        else if (c == endptr)
        {
            if (endptr == "-")
                printf("minus");
        }
        //test end
        c = strtok(NULL, " ");
    }
    printf("\n");
    //next: arrange in postfix and add to postfix array
    //next: solve problem in postfix array and set as answer
    printf("%s\t\t%s\n", "Postfix:", postfix);
    printf("%s\t\t%f\n", "Answer:", answer);
    printf("*********************************************\n");
}