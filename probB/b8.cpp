#include <stdio.h>
void liquid(int, int *, int *, int *, int *);

int main(void) {
  int num, gallons, quarts, pints, cups;
  printf("Enter the number of cups:\n");
  scanf("%d", &num);
  liquid(num, &gallons, &quarts, &pints, &cups);
  printf("The number of gallons is %d\n", gallons);
  printf("The number of quarts is %d\n", quarts);
  printf("The number of pints is %d\n", pints);
  printf("The number of cups is %d\n", cups);
  return 0;
}

void liquid(int n, int *g, int *q, int *p, int *c) {
  *g = n / 16;
  n %= 16;

  *q = n / 4;
  n %= 4;

  *p = n / 2;
  *c = n % 2;
}