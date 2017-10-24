#include <stdio.h>
#include <limits.h>

void bit_print(int);
int pack(char, char, char, char);
char unpack(int, int);
unsigned getbits(unsigned, int, int);
unsigned setbits(unsigned, int, int, unsigned);
unsigned invertbits(unsigned, int, int);

void bit_print(int a){
	int i;
	int n = sizeof(int) * CHAR_BIT;
	int mask = 1 << (n-1); // mask = 100...0
	
	for (i=1; i<=n; i++){
		putchar(((a & mask) == 0)? '0' : '1');
		a <<= 1;
		if (i % CHAR_BIT == 0 && i < n)
			putchar(' ');
	}
	putchar('\n');
}

int pack(char a, char b, char c, char d){
	int p=a;
	p = (p << CHAR_BIT) | b;
	p = (p << CHAR_BIT) | c;
	p = (p << CHAR_BIT) | d;
	return p;
}

char unpack(int p, int k){    // k=0, 1, 2, or 3
	int n = k * CHAR_BIT; // n = 0, 8, 16, 24
	unsigned mask = 255;  // mask = low-order byte
	
	mask <<= n;
	return ((p & mask) >> n);	
}

// getbits() extracts n bits from position p(start counting from the right-most bit) in x
unsigned getbits(unsigned x, int p, int n){
	unsigned temp = x >> (p+1-n);
	
	unsigned mask = 0;
	mask = ~mask;
	mask = mask << n;
	mask = ~mask;

	return temp & mask;
	// return (x >> (p+1-n)) & ~(~0<<n);
}

// setbits() returns x with the n bits that begin at posion p (right-adjusted) set to 
// the rightmost n bits in y, leaving the other bits unchanged.
unsigned setbits(unsigned x, int p, int n, unsigned y){
	unsigned mask = 0;
	mask = ~mask;
	mask = mask << n;
	mask = ~mask;

	unsigned temp = y & mask;
	temp = temp << (p+1-n);

	mask = mask << (p+1-n);
	mask = ~mask; 

	x = x & mask;
	return x | temp;
}

// invertbits() returns x with the n bits that begin at position p (right-adjusted) inverted,
// leaving the other bits unchanged. 
unsigned invertbits(unsigned x, int p, int n){
	unsigned nbits = getbits(x, p, n);
	nbits = ~nbits;
	return setbits(x, p, n, nbits);
}

int main(){
	int x = 19;

	printf("The binary rep. of %d is:\n", x);
	bit_print(x);

	int p=pack('w', 'x', 'y', 'z');
	printf("\n'w', 'x', 'y', and 'z' packed together is equal to %d. Its binary rep. is:\n", p);
	bit_print(p);
	printf("\ncalling unpack(p, 0) to extract the byte # 0 from the right:\n");
	bit_print(unpack(p, 0));
	printf("calling unpack(p, 1) to extract the byte # 1 from the right:\n");
	bit_print(unpack(p, 1));
	printf("calling unpack(p, 2) to extract the byte # 2 from the right:\n");
	bit_print(unpack(p, 2));
	printf("calling unpack(p, 3) to extract the byte # 3 from the right:\n");
	bit_print(unpack(p, 3));

	printf("\ncalling getbits(p, 20, 4) to extract 4 bits from bit # 20:\n");
	bit_print(getbits(p, 20, 4));

	int q=pack('a', 's', 'd', 'f');
	printf("\n'a', 's', 'd', and 'f' packed together (q) is equal to %d. Its binary rep. is:\n", q);
	bit_print(q);

	unsigned r=setbits(p, 15, 5, q); 
	printf("\ncalling setbits(p, 15, 5, q) returns %d. Its binary rep. is:\n", r);
	bit_print(r);

	
	r=invertbits(p, 19, 9); 
	printf("\ncalling invertbits(p, 19, 9) returns %d. Its binary rep. is:\n", r);
	bit_print(r);

	return 0;
}

