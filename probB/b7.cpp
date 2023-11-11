#include <stdio.h>
#define N 10

void extend(double[], double[], double[]);

int main(void) {
  double price[N] = {10.62, 14.89, 13.21, 16.55, 18.62,
                     9.47,  6.58,  18.32, 12.15, 3.98};
  double quantity[N] = {4, 8.5, 6, 8.35, 9, 15.3, 3, 5.4, 2.9, 4.8};
  double amount[N];
  extend(price, quantity, amount);
  for (int i = 0; i < N; i++)
    printf("%lf\n", amount[i]);
  return 0;
}

void extend(double p[], double q[], double a[]) {
  for (int i = 0; i < N; i++)
    a[i] = p[i] * q[i];
}