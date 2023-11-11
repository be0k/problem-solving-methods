#include <stdio.h>
#define N 9
void show(float[]);

int main(void) {
  float rates[N] = {6.5, 8.2, 8.5, 8.3, 8.6, 9.4, 9.6, 9.8, 10.0};
  show(rates);
  return 0;
}

void show(float r[]) {
  int i;
  for (i = 0; i < N - 1; i++) {
    printf("%.1f, ", r[i]);
  }
  printf("%.1f", r[i]);
}