// A Reverse Polish Calculator
// Supported operators are  +, -, *, /, sin, log (natural logarithm).
// Able to handle the following abnormal situations:
// 1. unrecognized operator, e.g. ^
// 2. illegal operand(s), e.g. 4 0 /
// 3. insufficient operand(s), 5 +
// 4. leftover operand(s) on stack, 2 3 -1 +

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define STACK_SIZE 		30

#define RADIANS( degrees ) ( degrees * M_PI / 180 )

// Erroneous cases
#define STACK_FULL   		-2
#define STACK_EMPTY   		-1
#define NORMAL			0
#define UNKNOWN_OPERATPR 	1
#define ILLEGAL_OPERAND		2
#define INSUFFICIENT_OPERAND	3
#define LEFTOVER_OPERAND	4

int myerror = NORMAL;


void push(double [], 	// input/ouput - the stack
    double,   	// input - data being pushed onto the stack
    int *,   	// input/output - pointer to the top of stack
    int);    	// constant - maximum size of stack

double		   	// output - data being popped out from the stack
pop(double [],  	// input/output - the stack
    int *);   	// input/output - pointer to top of stack

void push(double stack[],
  double item,
  int *top,
  int max_size){

  if(*top < max_size-1){
    ++(*top);
    stack[*top] = item;
    myerror = NORMAL;
  }
  else
    myerror = STACK_FULL;
}

double pop(double stack[],
  int *top){

  double item;
  if (*top >= 0){
    item = stack[*top];
    --(*top);
    myerror = NORMAL;
  }
  else{
    item = STACK_EMPTY; // not used when myerror is not NORMAL
    myerror = STACK_EMPTY;
  }

  return item;
}

int main(void)
{
  double stack[STACK_SIZE];   // stack holding operands    
  int s_top = STACK_EMPTY;    // index of the top element on stack
  double x, y;		    // operands

  char s[100]; 		    // input string in reverse polish
  char delim[]=" ";      	    // delimiter
  char *c; 		    // token in s that is currently being processed
  myerror = 0; 	            // error code

  printf("\nPlease enter a Reverse Polish equation. Supported operators are  +, -, *, /, sin, log.\n");
  printf("Equation: ");

  while(fgets(s, sizeof(s), stdin)!=NULL){  
    s[strlen(s)-1]='\0';// remove '\n' in s
    s_top = -1; 	    // reset stack
    myerror = NORMAL;
    c = strtok(s, delim);

    char *endptr;
    double temp = strtod(c,&endptr);
    if (s != endptr && *endptr == '\0')
      push(stack, temp, &s_top, STACK_SIZE);   
    else
      myerror = UNKNOWN_OPERATPR;

    while((myerror == 0) && ((c = strtok(NULL, delim))!=NULL)){       
      if(strcmp(c, "+") == 0)                  
      {                                            
        y=pop(stack, &s_top);                         
        x=pop(stack, &s_top);
        // if (y==STACK_EMPTY || x==STACK_EMPTY){
        if (myerror == STACK_EMPTY){
          myerror = INSUFFICIENT_OPERAND;
          break;
        }
        push(stack, x+y, &s_top, STACK_SIZE);
      }
      else  if(strcmp(c, "-") == 0)  
      {
        y=pop(stack, &s_top);
        x=pop(stack, &s_top);
          // if (y==STACK_EMPTY || x==STACK_EMPTY){
        if (myerror == STACK_EMPTY){
          myerror = INSUFFICIENT_OPERAND;
          break;
        }

        push(stack, x-y, &s_top, STACK_SIZE);
      }
      else  if(strcmp(c, "/") == 0)  
      {
        y=pop(stack, &s_top);
        x=pop(stack, &s_top);

            // if (y==STACK_EMPTY || x==STACK_EMPTY){
        if (myerror == STACK_EMPTY){
          myerror = INSUFFICIENT_OPERAND;
          break;
        }
        if (y==0){
          myerror = ILLEGAL_OPERAND;
          break;
        }

        push(stack, x/y, &s_top, STACK_SIZE);
      }
      else  if(strcmp(c, "*") == 0)  
      {
        y=pop(stack, &s_top);
        x=pop(stack, &s_top);

              // if (y==STACK_EMPTY || x==STACK_EMPTY){
        if (myerror == STACK_EMPTY){
          myerror = INSUFFICIENT_OPERAND;
          break;
        }

        push(stack, x*y, &s_top, STACK_SIZE);
      }
      else  if(strcmp(c, "sin") == 0)  
      {
        y=pop(stack, &s_top);

                // if (y==STACK_EMPTY){
        if (myerror == STACK_EMPTY){
          myerror = INSUFFICIENT_OPERAND;
          break;
        }

        push(stack, sin(RADIANS(y)), &s_top, STACK_SIZE);
      }
      else  if(strcmp(c, "log") == 0)  
      {
        y=pop(stack, &s_top);

                  // if (y==STACK_EMPTY){
        if (myerror == STACK_EMPTY){
          myerror = INSUFFICIENT_OPERAND;
          break;
        }

        if(y<=0){
          myerror = ILLEGAL_OPERAND;
          break;
        }
        push(stack, log(y), &s_top, STACK_SIZE);
      }
      else
      {
        char *endptr;
        double temp = strtod(c,&endptr);
        if (s != endptr && *endptr == '\0')
          push(stack, temp, &s_top, STACK_SIZE);   
        else{
          myerror = UNKNOWN_OPERATPR;
          break; 
        }
      }    

    }

    if (myerror == 0){
      if (s_top != 0){
        myerror = LEFTOVER_OPERAND;
        printf("Error: Leftover Operand(s) on Stack.\n");
      }
      else
        printf("result = %lf\n", pop(stack, &s_top));
    }
    else{
      switch(myerror){
        case UNKNOWN_OPERATPR:
        printf("Error: Unknown Operator %s\n", c);
        break;
        case ILLEGAL_OPERAND:
        printf("Error: Illegal Operand for Operator %s\n", c);
        break;
        case INSUFFICIENT_OPERAND:
        printf("Error: Insufficient Operand(s) for Operator %s\n", c);
        break;
                      /*case LEFTOVER_OPERAND:
                        printf("Error: Leftover Operand(s) on Stack\n");
                        break;
                        */
      }
    }
    printf("-----------------\n");

    printf("Next Equation Please: "); 

  }
  return 0;
}

