#include <stdio.h>
#define N 1000

void get_num(char[]);
int sign(char[]);
int c_to_i(char[], int[], int);
void cal(int[], int[], int[], int[], int[], int, int);
void skip_zero(int[], int);

int main(void) {
  char c_a[N], c_b[N];
  int a[N], b[N], plus[N + 1], subt[N + 1], mul[N * 2 + 1];
  int a_len, b_len;   // 0부터 '\0'까지의 길이(\n 없음)
  int a_sign, b_sign; // 0은 -, 1은 +
  int big = 0;        // 0은 a>=b 1은 a<b
  int i;

  get_num(c_a);
  get_num(c_b);

  a_sign = sign(c_a);
  b_sign = sign(c_b);
  a_len = c_to_i(c_a, a, a_sign);
  b_len = c_to_i(c_b, b, b_sign);
  if (a_sign == 0)
    a[0] = 0;
  if (b_sign == 0)
    b[0] = 0;
  if (a_len > b_len) {
    big = 0;
  } else if (a_len < b_len) {
    big = 1;
  } else {
    i = 0;
    while (i < a_len) {
      if (a[i] > b[i]) {
        big = 0;
        break;
      } else if (a[i] < b[i]) {
        big = 1;
        break;
      } else {
        i++;
      }
    }
  }

  if (big == 0)
    cal(a, b, plus, subt, mul, a_len, b_len);
  else
    cal(b, a, plus, subt, mul, b_len, a_len);

  // big   0은 a>=b 1은 a<b
  // sign  0은 -, 1은 +
  if (big == 0) {
    if (a_sign == 1 && b_sign == 1) {
      // 11 1
      skip_zero(plus, N);
      skip_zero(subt, N);
      skip_zero(mul, N * 2);
    } else if (a_sign == 0 && b_sign == 1) {
      // -11 1
      printf("-");
      skip_zero(subt, N);
      printf("-");
      skip_zero(plus, N); // modify
      printf("-");
      skip_zero(mul, N * 2);
    } else if (a_sign == 1 && b_sign == 0) {
      // 11 -1
      skip_zero(subt, N);
      skip_zero(plus, N);
      printf("-");
      skip_zero(mul, N * 2);
    } else {
      //-11 -1
      printf("-");
      skip_zero(plus, N);
      skip_zero(subt, N);
      skip_zero(mul, N * 2);
    }
  } else {
    if (a_sign == 1 && b_sign == 1) {
      // 1 11
      skip_zero(plus, N);
      printf("-");
      skip_zero(subt, N);
      skip_zero(mul, N * 2);
    } else if (a_sign == 0 && b_sign == 1) {
      //-1 11
      skip_zero(subt, N);
      printf("-");
      skip_zero(plus, N);
      printf("-");
      skip_zero(mul, N * 2);
    } else if (a_sign == 1 && b_sign == 0) {
      // 1 -11
      printf("-");
      skip_zero(subt, N);
      skip_zero(plus, N); // modify
      printf("-");
      skip_zero(mul, N * 2);
    } else {
      //-1 -11
      printf("-");
      skip_zero(plus, N);
      skip_zero(subt, N);
      skip_zero(mul, N * 2);
    }
  }

  // for (int x = 0; x < a_len; x++)
  //   printf("%d", a[x]);
  // printf("\n");
  // for (int x = 0; x < b_len; x++)
  //   printf("%d", b[x]);
  return 0;
}

void get_num(char arr[]) {
  int t = -1;
  char c;
  do {
    t++;
    c = getchar();
    arr[t] = c;
  } while (arr[t] != '\n');
  arr[t] = '\0';
}

int sign(char arr[]) {
  int m = 1;
  if (arr[0] == '-')
    m = 0;
  return m;
}

int c_to_i(char c[], int i[], int s) {
  int t;
  t = 0;
  while (c[t] != '\0') {
    i[t] = (int)c[t] - 48;
    t++;
  }

  return t;
}

// a_len >= b_len
void cal(int a[], int b[], int p[], int s[], int m[], int a_len, int b_len) {
  int i, j;
  for (i = 0; i <= N; i++) {
    p[i] = 0;
    s[i] = 0;
    m[i] = 0;
  }
  for (i = N; i <= N * 2; i++)
    m[i] = 0;

  // plus
  for (i = 0; i < a_len; i++) {
    if (i < b_len) {
      p[N - i] = p[N - i] + (a[a_len - i - 1] + b[b_len - i - 1]) % 10;
      p[N - i - 1] = (a[a_len - i - 1] + b[b_len - i - 1]) / 10;
    } else {
      p[N - i] = p[N - i] + a[a_len - i - 1];
    }
  }

  // subtract
  for (i = 0; i < a_len; i++) {
    if (i < b_len) {
      if (s[N - i] + (a[a_len - i - 1] - b[b_len - i - 1]) < 0) {
        s[N - i] = s[N - i] + 10 + (a[a_len - i - 1] - b[b_len - i - 1]);
        s[N - i - 1]--;
      } else {
        s[N - i] = s[N - i] + (a[a_len - i - 1] - b[b_len - i - 1]);
      }
    } else {
      s[N - i] = a[a_len - i - 1] + s[N - i];
    }
  }

  // multiple
  for (i = 0; i < b_len; i++) {
    for (j = 0; j < a_len; j++) {
      m[(N * 2) - i - j] =
          m[(N * 2) - i - j] + (a[a_len - j - 1] * b[b_len - i - 1]);
    }
  }
  for (i = N * 2; i >= N * 2 - b_len - a_len; i--) {
    m[i - 1] = m[i - 1] + m[i] / 10;
    m[i] = m[i] % 10;
  }
}

void skip_zero(int arr[], int len) {
  int i = 0;
  while (arr[i] == 0 && i < len)
    i++;

  while (i <= len) {
    printf("%d", arr[i]);
    i++;
  }
  printf("\n");
}