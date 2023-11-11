#include <stdio.h>
#define N 100

int main(void) {

  int i, count;
  int maxage = -1, minage = 1000;
  int maxscore = -1, minscore = 1000;
  int maxagecnt = 0, minagecnt = 0, maxscorecnt = 0, minscorecnt = 0;
  int age[N], maxagegrp[N], minagegrp[N];
  int score[N], maxscoregrp[N], minscoregrp[N];

  // init data
  for (i = 0; i < N; i++) {
    int tmp_age, tmp_score;
    // printf("Put age and score pair (End:-1,-1): ");
    scanf("%d %d", &tmp_age, &tmp_score);
    if (tmp_age == -1 && tmp_score == -1)
      break;
    age[i] = tmp_age;
    score[i] = tmp_score;
  }
  count = i;

  // except(first data == -1)
  if (score[0] == -1 && age[0] == -1) {
    printf("No data");
    return 0;
  }

 
  for (int k = 0; k < count; k++) {
    
     // max_age
    if (maxage < age[k]) {
      maxage = age[k];
      maxagecnt = 0;
      maxagegrp[maxagecnt] = k;
    } else if (maxage == age[k]) {
      maxagecnt += 1;
      maxagegrp[maxagecnt] = k;
    }

    //max_score
    if (maxscore < score[k]) {
      maxscore = score[k];
      maxscorecnt = 0;
      maxscoregrp[maxscorecnt] = k;
    } else if (maxscore == score[k]) {
      maxscorecnt += 1;
      maxscoregrp[maxscorecnt] = k;
    }

    //min_age
    if (minage > age[k]) {
      minage = age[k];
      minagecnt = 0;
      minagegrp[minagecnt] = k;
    } else if (minage == age[k]) {
      minagecnt += 1;
      minagegrp[minagecnt] = k;
    }

    //min_score
    if (minscore > score[k]) {
      minscore = score[k];
      minscorecnt = 0;
      minscoregrp[minscorecnt] = k;
    } else if (minscore == score[k]) {
      minscorecnt += 1;
      minscoregrp[minscorecnt] = k;
    }
  }

  // print_max_age
  printf("%d ", maxage);
  for (int t = 0; t <= maxagecnt; t++) {
    printf("%d ", score[maxagegrp[t]]);
  }
  printf("\n");

  // print_min_age
  printf("%d ", minage);
  for (int t = 0; t <= minagecnt; t++) {
    printf("%d ", score[minagegrp[t]]);
  }
  printf("\n");

  // print_max_score
  printf("%d ", maxscore);
  for (int t = 0; t <= maxscorecnt; t++) {
    printf("%d ", age[maxscoregrp[t]]);
  }
  printf("\n");

  // print_min_score
  printf("%d ", minscore);
  for (int t = 0; t <= minscorecnt; t++) {
    printf("%d ", age[minscoregrp[t]]);
  }
  printf("\n");

  return 0;
}
