#include <stdio.h>

void secs(int *totSec, int hours, int minutes, int seconds);

int main() {
  int hours, minutes, seconds;
  int totSec;

  printf("Type hours, minutes, ans seconds (e.g., 10 10 10):\n");
  scanf("%d %d %d", &hours, &minutes, &seconds);
  secs(&totSec, hours, minutes, seconds);
  printf("Total seconds: %d\n", totSec);

  return 0;
}

// Please write down your solution below

void secs(int *totSec, int h, int m, int s) { *totSec = h * 3600 + m * 60 + s; }
