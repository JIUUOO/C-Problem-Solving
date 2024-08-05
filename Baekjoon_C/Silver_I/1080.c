#include <stdio.h>

void flipElem(int *array[], int n, int m) {
  for (int i = n - 1; i <= n + 1; i++) {
    for (int j = m - 1; j <= m + 1; j++) {
      array[i][j] = array[i][j] == 0 ? 1 : 0;
    }
  }
}

int getAllSequence(int num, ) {
    getAllSequence(
}

int main(void) {

    int n, m;
    n = 3;
    m = 4;
    int arrayA[n][m] = {0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0};
    int arrayB[n][m] = {{1, 0, 0, 1}, {1, 0, 1, 1}, {1, 0, 0, 1}};

    int arrayT[n][m];

    return 0;
}