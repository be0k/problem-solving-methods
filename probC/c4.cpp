#include <stdio.h>
#define N 1000

int main() {
  char str[N], sub[N];
  int str_len = 0, sub_len = 0;
  int check = 0;
  int i, j;
  fgets(str, N, stdin);
  fgets(sub, N, stdin);
  while (str[str_len] != '\n')
    str_len++;
  while (sub[sub_len] != '\n')
    sub_len++;
  i = 0;
  while (i < str_len - sub_len + 1) {
    if (str[i] == sub[0]) {
      for (j = 1; j < str_len; j++) {
        if (str[i + j] != sub[j])
          break;
      }
      if (j == sub_len) {
        check += 1;
        i += sub_len - 1;
      }
    }
    i++;
  }
  printf("%d", check);
  return 0;
}