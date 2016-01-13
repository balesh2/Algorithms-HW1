#include <stdio.h>
#include <time.h>
#include <stdlib.h>

/*******************************************************************************
 * ALGORITHM 2 -- BETTER ENUMERATION
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
  int  sum, maxsum, i, j, m;
  int *arr;
  clock_t begin, end;
  double time_spent;
  int n[18] = {100, 200, 300, 400, 500, 600, 700, 800, 900, 1000, 2000, 3000, 4000, 5000, 6000, 7000, 8000, 9000};

  srand(time(NULL));

  maxsum = 0;

  for(m=0; m<18; m++) {
    arr = malloc(sizeof(int) * n[m]);

    for(i = 0; i < n[m]; i++)
    {
      arr[i] = randnum();
      //printf("%d ", arr[i]);
    }
    //printf("\n");

    begin = clock();
    for(i = 1; i < n[m]; i++)
    {
      sum = 0;
      for(j = 0; j < (i+1); j++)
      {
        sum += arr[j];
        if(sum > maxsum)
        {
          maxsum = sum;
        }
      }
      for(j = 0; j < (i+1); j++)
      {
        sum -= arr[j];
        if(sum > maxsum)
        {
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
