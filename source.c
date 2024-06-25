#include <stdio.h>

#define SIZE 40

int fiboCountingList[SIZE][3] = {
    {0},
    {1},
};

long long unsigned int fibo(int n, int i) {
  if (n == 1 || n == 0) {
    printf("%d ", n);
    fiboCountingList[n][0] = n;

  } else {
    fiboCountingList[n][0] = fibo(n - 1, i) + fibo(n - 2, i);
  }
  return fiboCountingList[n][0];
}

int main(void) {
  int times = 0;
  scanf("%d", &times);

  int testList[times];
  for (int i = 0; i < times; i++) {
    scanf("%d", &testList[i]);
  }

  int tl;

  for (int i = 0; i < times; i++) {
    tl = testList[i];
    fibo(tl, tl);
    puts("");
  }

  return 0;
}