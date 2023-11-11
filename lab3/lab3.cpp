#include <stdio.h>
#include <string.h>

struct {
  int RRN;
  char name[20];
  float salary;
  float bonus;
} employee[1000];

int main() {
  int num, idx, i, j;
  float slry, bns;
  char nm[20];
  scanf("%d", &num);
  for (i = 0; i < num; i++) {
    scanf("%d %s %f %f", &idx, nm, &slry, &bns);
    for (j = 0; j < i; j++) {
      if (idx == employee[j].RRN) {
        printf("Error: RRN should be unique\n");
        num--;
        j = i--;
        break;
      }
    }
    if (i == j) {
      if (slry <= bns) {
        printf("Error: Bonus should be less than salary\n");
        num--;
        i--;
      } else {
        employee[i].salary = slry;
        employee[i].bonus = bns;
        employee[i].RRN = idx;
        strcpy(employee[i].name, nm);
      }
    }
  }

  for (i = 0; i < num; i++) {
    printf("%d %s %.0f %.0f\n", employee[i].RRN, employee[i].name,
           employee[i].salary, employee[i].bonus);
  }
  return 0;
}