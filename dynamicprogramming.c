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
  int maxsub, maxsuf, i, j, maxsum, m, *a;
  clock_t begin, end;
  double time_spent;
  int n[18] = {100, 200, 300, 400, 500, 600, 700, 800, 900, 1000, 2000, 3000, 4000, 5000, 6000, 7000, 8000, 9000};

  srand(time(NULL));


  maxsub = 0;
  maxsuf = 0;

  for(m=0; m<18; m++) {
    a = malloc(sizeof(int)*n[m]);

    begin = clock();
    for(i=1; i<n[m]; i++) {
      a[i] = randnum();
      //printf("%d ", a[i]);
    }
    //printf("\n");

    for(i=0; i<n[m]; i++) {
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
    end = clock();

    //printf("maxsuf: %d\n", maxsuf);
    //printf("maxsub: %d\n", maxsub);

    if(maxsub > maxsuf) {
      maxsum = maxsub;
    }
    else {
      maxsum = maxsuf;
    }

    time_spent = (double)(end - begin) / CLOCKS_PER_SEC;

    printf("time spent: %f\n", time_spent);
  }

  return 0;
}
