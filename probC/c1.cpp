#include <stdio.h>

struct INFO {
  int car_number;
  int miles;
  int gallons;
};
 
int main() {
  int num, m = 0, g = 0;
  scanf("%d", &num);
  struct INFO arr[num];
  for (int i = 0; i < num; i++) {
    scanf("%d %d %d", &arr[i].car_number, &arr[i].miles, &arr[i].gallons);
    m += arr[i].miles;
    g += arr[i].gallons;
    printf("ID=%d Miles=%d Gallons=%d Ave.Miles=%.2f(miles/gal)\n", i,
           arr[i].car_number, arr[i].miles,
           (float)arr[i].miles / arr[i].gallons);
  }
  printf("The average of miles per gallons for all the cars: %.2f",
         (float)m / g);
  return 0;
}
