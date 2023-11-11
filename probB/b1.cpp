#include <stdio.h>
#define N 5
void totpay(float[N], float[N], float[N]);

int main() {
  /* declarations   */
  float base[N], overtime[N], total[N];

  for (int i = 0; i < N; i++)
    scanf("%f %f", &base[i], &overtime[i]);

  /* read and store values in array pay */
  totpay(base, overtime, total);

  /* print total for each person per line */
  for (int i = 0; i < N; i++)
    printf("%f\n", total[i]);
  return 0;
}

void totpay(float b[], float o[], float t[]) {
  /* compute and store total for each person  */
  for (int k = 0; k < N; k++) {
    t[k] = b[k] + o[k];
  }
}
