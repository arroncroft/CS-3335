#include <stdio.h>
#include <limits.h>
#include <math.h>

int f(int);

int main(void){
	int i, t, funval;
	
	int low=-9, high=5;
	int f_min=INT_MAX, f_max=INT_MIN;
	for (t=low; t<=high;t++){
		printf("f(%2d)=%3d\n",t,f(t));
		if(f(t)<f_min)
			f_min=f(t);
		if(f(t)>f_max)
			f_max=f(t);
        }

	printf("--\n");
	printf("min=%3d\n",f_min);
	printf("max=%3d\n",f_max);
	printf("--\n");
	// int max = f(high)>f(low)?f(high):f(low);
	int max = f_max-f_min+1;
	char plot[max + 2];
	for (i=f_min; i<=f_max+5; i+=5){
		printf("%5d",i);
	}
	printf("\n");

	
	for (i=0; i<=f_max-f_min+5; i+=5){
		printf("    |");
	}
	printf("\n");

	//for (i=0; i<=max+1; i++){
	for (i=0; i<=max+1; i++){
		plot[i]=' ';
	}

	for (t=low; t<=high; t++){
		funval=f(t);
		plot[funval-f_min] = '*';
		plot[funval-f_min+1] = '\0';
		printf("t=%2d%s\n",t,plot);
		plot[funval-f_min] = ' ';
		plot[funval-f_min+1] = ' ';
	}
	return 0;
}


int f(int t){
	//return (t*t-4*t+5);
//	return (-t*t+4*t-1);
	//return (sin(t)*10);
	if (t>0)
		return t*2;
	else
		return t*8;
}
