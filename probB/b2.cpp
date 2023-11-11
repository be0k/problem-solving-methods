#include <stdio.h>

void calculate(int, int, int *, int *, int *, int *);

int main(void) {
  // write
  int N1, N2, re1, re2, re3, re4;
  scanf("%d %d", &N1, &N2);
  calculate(N1, N2, &re1, &re2, &re3, &re4);
  printf("%d, %d, %d, %d", re1, re2, re3, re4);
  return 0;
}

void calculate(int n1, int n2, int *re1, int *re2, int *re3, int *re4) {
  *re1 = n1 * n2;
  *re2 = n1 / n2;
  *re3 = n1 % n2;
  *re4 = n1 + n2;
}
