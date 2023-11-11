#include <stdio.h>

struct Date {
  int month;
  int day;
  int year;
};

Date recent(Date a, Date b) {
  // Please write down your solution
  Date temp;
  if (a.year > b.year) {
    temp = a;
  } else if (a.year < b.year) {
    temp = b;
  } else {
    if (a.month > b.month) {
      temp = a;
    } else if (a.month < b.month) {
      temp = b;
    } else {
      if (a.day > b.day) {
        temp = a;
      } else if (a.day < b.day) {
        temp = b;
      } else {
        temp = a;
      }
    }
  }
  return temp;
}

int main() {
  Date date;
  Date a, b;

  scanf("%d/%d/%d", &a.month, &a.day, &a.year);
  scanf("%d/%d/%d", &b.month, &b.day, &b.year);

  printf("%d", a.month);

  date = recent(a, b);
  printf("%d/%d/%d\n", date.month, date.day, date.year);

  return 0;
}
