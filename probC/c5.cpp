#include <stdio.h>
#define N 1000

int main() {
  char str[N], sub[N];
  int str_len = 0, sub_len = 0;
  int check, cp = 0;
  int i, j;
  fgets(str, N, stdin);
  fgets(sub, N, stdin);
  while (str[str_len] != '\n')
    str_len++;
  while (sub[sub_len] != '\n') {
    if (sub[sub_len] == '*')
      cp = sub_len;
    sub_len++;
  }

  check = cp ? 0 : 1;

  i = 0;
  while (i <= str_len - sub_len && check == 0) {
    if (str[i] == sub[0]) {
      for (j = 1; j < cp; j++) {
        if (str[i + j] != sub[j])
          break;
      }
      if (j == cp) {
        check += 1;
        i += cp - 1;
      }
    }
    i++;
  }

  // +1 because of *
  // arr[cp] == *
  cp++;
  while (i <= str_len - sub_len + cp && check == 1) {
    if (str[i] == sub[cp]) {
      for (j = 1; j < sub_len - cp; j++) {
        if (str[i + j] != sub[j + cp])
          break;
      }
      if (j == sub_len - cp) {
        check += 1;
      }
    }
    i++;
  }
  if (check == 2)
    printf("Match found!");
  else
    printf("There is no matched pattern!");
  return 0;
}