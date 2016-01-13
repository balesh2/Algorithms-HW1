#include <stdio.h>
#include <time.h>
#include <stdlib.h>

/*******************************************************************************
 * ALGORITHM 1 -- ENUMERATION
 ******************************************************************************/

int randnum() {
  int num, pos;

  num = rand() % 100;
  pos = rand() % 2;

  if(pos == 1) {
    num = num * -1;
  }

  return num;
}

int main() {
  int sum, maxsum, i, j, k, n;
  int* a;
  clock_t begin, end;
  double time_spent;

  srand(time(NULL));

  n = 100;
  sum = 0;
  maxsum = 0;

  a = malloc(sizeof(int)*n);

  for(i=0; i<n; i++) {
    a[i] = randnum();
    //printf("%d ", a[i]);
  }
  //printf("\n");

  begin = clock();
  for(i=0; i<(n-1); i++) {
    for(j=1; j<n; j++) {
      sum = 0;
      for(k=i; k<(j+1); k++) {
        sum += a[k];
      }
      if(sum > maxsum) {
        maxsum = sum;
      }
    }
  }
  end = clock();
  time_spent = (double)(end - begin) / CLOCKS_PER_SEC;

  printf("maxsum: %d\n", maxsum);
  printf("time spent: %f\n", time_spent);

  return 0;
}
