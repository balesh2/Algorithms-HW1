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
  int sum, maxsum, i, j, k, m;
  int* a;
  clock_t begin, end;
  double time_spent;
  int n[9] = {100, 200, 300, 400, 500, 600, 700, 800, 900};

  srand(time(NULL));

  sum = 0;
  maxsum = 0;

  for(m=0; m<9; m++) {
    a = malloc(sizeof(int)*n[m]);

    for(i=0; i<n[m]; i++) {
      a[i] = randnum();
      //printf("%d ", a[i]);
    }
    //printf("\n");

    begin = clock();
    for(i=0; i<(n[m]-1); i++) {
      for(j=1; j<n[m]; j++) {
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
  }

  return 0;
}
