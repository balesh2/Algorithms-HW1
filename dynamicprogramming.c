#include <stdio.h>
#include <time.h>
#include <stdlib.h>

/*******************************************************************************
 * ALGORITHM 3 -- DYNAMIC PROGRAMMING
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
  int maxsub, maxsuf, i, j, n, *a, maxsum;

  srand(time(NULL));

  maxsub = 0;
  maxsuf = 0;
  n = 10;
  a = malloc(sizeof(int)*n);

  for(i=1; i<n; i++) {
    a[i] = randnum();
    printf("%d ", a[i]);
  }
  printf("\n");

  for(i=0; i<n; i++) {
    if((maxsuf + a[i]) > 0) {
      maxsuf += a[i];
    }
    else {
      maxsuf = 0;
    }
    if(maxsub < maxsuf) {
      maxsub = maxsuf;
    }
  }

  printf("maxsuf: %d\n", maxsuf);
  printf("maxsub: %d\n", maxsub);

  if(maxsub > maxsuf) {
    maxsum = maxsub;
  }
  else {
    maxsum = maxsuf;
  }

  printf("%d\n", maxsum);

  return 0;
}
