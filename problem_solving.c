#include <stdio.h>

#define SIZE 40

int fiboList[SIZE] = {
    0,
};

long long unsigned int fibo(int n, int *arr) {
  if (n == 1 || n == 0) {
    arr[n]++;
    return n;
  }

  return fibo(n - 1, arr) + fibo(n - 2, arr);
}

int main(void) {
  int times = 0;
  scanf("%d", &times);

  int testList[times];
  for (int i = 0; i < times; i++) {
    scanf("%d", &testList[i]);
  }

  // count the number of zeros and ones
  int count[2] = {0, 0};

  for (int i = 0; i < times; i++) {
    fibo(testList[i], count);
    printf("%d %d\n", count[0], count[1]);

    // initialize counting
    count[0] = 0;
    count[1] = 0;
  }
  return 0;
}