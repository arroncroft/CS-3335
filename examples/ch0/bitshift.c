#include <stdio.h>
#include <limits.h>

void bit_print(int);

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

int main(){
  signed int i=-1;
  unsigned u=-1;

  printf("i=%d, u=%u\n", i, u);
  bit_print(i);
  bit_print(u);

  puts("-----");
  puts("Experiment 1:");
  if (i<<1 == u<<1)
    printf("Zeros are left-shifted in for <<.\n");
  else
    printf("Signed bits are left-shifted in for <<.\n");

  printf("After one left shift, i=%d, u=%u\n", i<<1, u<<1);
  bit_print(i<<1);
  bit_print(u<<1);

  puts("-----");
  puts("Experiment 2:");
  if (i<<2 == u<<2)
    printf("Zeros are left-shifted in for <<.\n");
  else
    printf("Signed bits are left-shifted in for <<.\n");

  printf("After two left shifts, i=%d, u=%u\n", i<<2, u<<2);
  bit_print(i<<2);
  bit_print(u<<2);

  puts("-----");
  puts("Experiment 3:");
  if (i>>1 == u>>1)
    printf("Zeros are shifted in for >>.\n");
  else
    printf("Signed bits are shifted in for >>.\n");

  printf("After one right shift, i=%d, u=%u\n", i>>1, u>>1);
  bit_print(i>>1);
  bit_print(u>>1);

  puts("-----");
  puts("Experiment 4:");
  if (i>>2 == u>>2)
    printf("Zeros are shifted in for >>.\n");
  else
    printf("Signed bits are shifted in for >>.\n");

  printf("After two right shifts, i=%d, u=%u\n", i>>2, u>>2);
  bit_print(i>>2);
  bit_print(u>>2);

  return 0;
}
