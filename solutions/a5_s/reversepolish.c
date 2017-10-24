// A Reverse Polish Calculator
// Supported operators are  +, -, *, /, sin, log (natural logarithm).
// Legal input is assumed. 

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define STACK_SIZE 	30

#define STACK_FULL 	-2
#define STACK_EMPTY 	-1
#define NORMAL 		0

#define RADIANS( degrees ) ( degrees * M_PI / 180 )

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
  int s_top = STACK_EMPTY;
  double x, y;

  char s[100]; // input string in reverse polish
  char delim[]=" ";   // delimiter
  char *c;

  printf("\nPlease enter a Reverse Polish equation. Supported operators are  +, -, *, /, sin, log\n");
  printf("Equation: ");

  while(fgets(s, sizeof(s), stdin)!=NULL){  
    s[strlen(s)-1]='\0'; // Replace '\n' with '\0' at the end of s
    c = strtok(s, delim);

    // first operand
    push(stack, strtod(c, NULL), &s_top, STACK_SIZE);   

    while((c = strtok(NULL, delim))!=NULL){       
      if(strcmp(c, "+") == 0)                  
      {                                            
        y=pop(stack, &s_top);                         
        x=pop(stack, &s_top);
        push(stack, x+y, &s_top, STACK_SIZE);
      }
      else  if(strcmp(c, "-") == 0)  
      {
        y=pop(stack, &s_top);
        x=pop(stack, &s_top);
        push(stack, x-y, &s_top, STACK_SIZE);
      }
      else  if(strcmp(c, "/") == 0)  
      {
        y=pop(stack, &s_top);
        x=pop(stack, &s_top);
        push(stack, x/y, &s_top, STACK_SIZE);
      }
      else  if(strcmp(c, "*") == 0)  
      {
        y=pop(stack, &s_top);
        x=pop(stack, &s_top);
        push(stack, x*y, &s_top, STACK_SIZE);
      }
      else  if(strcmp(c, "sin") == 0)  
      {
        y=pop(stack, &s_top);
        push(stack, sin(RADIANS(y)), &s_top, STACK_SIZE);
      }
      else  if(strcmp(c, "log") == 0)  
      {
        y=pop(stack, &s_top);
        push(stack, log(y), &s_top, STACK_SIZE);
      }
      else
      {
        // one more operand
        push(stack, strtod(c, NULL), &s_top, STACK_SIZE);    
      }    

    }

    printf("result = %lf\n", pop(stack, &s_top));
    printf("-----------------\n");

    printf("Next Equation Please: "); 
  }
  return 0;
}

