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
  int  sum, maxsum, i, j, n;
  int *arr;

  srand(time(NULL));

  maxsum = 0;
  n = 10;
  arr = malloc(sizeof(int) * n);

  for(i = 0; i < n; i++)
  {
    arr[i] = randnum();
    printf("%d ", arr[i]);
  }
  printf("\n");

  for(i = 1; i < n; i++)
  {
    sum = 0;
    for(j = 0; j < i; j++)
    {
      sum += arr[j];
      if(sum > maxsum)
      {
        maxsum = sum;
      }
    }
    for(j = 0; j < i; j++)
    {
      sum -= arr[j];
      if(sum > maxsum)
      {
        maxsum = sum;
      }
    }
  }
  printf("%d\n", maxsum);

  return 0;
}
