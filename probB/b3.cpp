#include <stdio.h>

void change(float, int *, int *, int *, int *);

// You should not modify the main function

int main() {
  float total;
  int quarters, dimes, nickels, pennies;

  printf("Enter the amount of money in your pocket:\n");
  scanf("%f", &total);

  quarters = 0;
  dimes = 0;
  nickels = 0;
  pennies = 0;
  change(total, &quarters, &dimes, &nickels, &pennies);

  printf("TOTAL VALUE ENTERED: %.2f\n", total);
  printf("%9d quarters\n", quarters);
  printf("%9d dimes\n", dimes);
  printf("%9d nickels\n", nickels);
  printf("%9d pennies\n", pennies);

  return 0;
}

// Write down the change function below

// Pennies are worth 1 cent. Nickels are worth 5 cents. Dimes are worth 10
// cents. Quarters are worth 25 cents.

void change(float t, int *q, int *d, int *n, int *p) {
  t *= 100;
  *q = t / 25;
  t = (int)t % 25;

  *d = t / 10;
  t = (int)t % 10;

  *n = t / 5;
  *p = (int)t % 5;
}