#include <stdio.h>

#define SIZE 41

int fiboList[SIZE];
int fiboCountingList[SIZE][2];

int fibo(int n, int i) {
  if (fiboList[n] > 0) {
    fiboCountingList[i][0] += fiboCountingList[n][0];
    fiboCountingList[i][1] += fiboCountingList[n][1];
    return fiboList[n];
  }

  if (n == 1 || n == 0) {
    fiboCountingList[i][n]++;
    fiboList[n] = n;
    return fiboList[n];
  } else {
    fiboList[n] = fibo(n - 1, n) + fibo(n - 2, n);
    return fiboList[n];
  }
}

int main(void) {
  // initilize fibo arrays
  for (int i = 0; i < SIZE; i++) {
    fibo(i, i);
    // printf("%d %d %d\n", fiboList[i], fiboCountingList[i][0],
    //        fiboCountingList[i][1]);
  }

  int times = 0;
  scanf("%d", &times);

  int testList[times];
  for (int i = 0; i < times; i++) {
    scanf("%d", &testList[i]);
  }

  int tl;

  for (int i = 0; i < times; i++) {
    tl = testList[i];
    printf("%d %d\n", fiboCountingList[tl][0], fiboCountingList[tl][1]);
  }

  return 0;
}