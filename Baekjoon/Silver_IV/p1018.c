#include <stdbool.h>
#include <stdio.h>

int boardTypeA[8][8];
int boardTypeB[8][8];

int getMinDiff(int board[8][8]) {
  int sumDiffA = 0;
  int sumDiffB = 0;

  // comparing 8 by 8 with 8 by 8
  for (int i = 0; i < 8; i++) {
    for (int j = 0; j < 8; j++) {
      (board[i][j] != boardTypeA[i][j]) && (sumDiffA++);
      (board[i][j] != boardTypeB[i][j]) && (sumDiffB++);
    }
  }

  return sumDiffA < sumDiffB ? sumDiffA : sumDiffB;
}

int main(void) {
  int n, m;
  scanf("%d %d", &n, &m);

  int inputBoard[n][m];
  char inputCell;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      scanf(" %c", &inputCell);
      (inputCell == 'B') && (inputBoard[i][j] = 0);
      (inputCell == 'W') && (inputBoard[i][j] = 1);
    }
  }
  // puts("\n");
  // for (int i = 0; i < n; i++) {
  //   for (int j = 0; j < m; j++) {
  //     printf("%d", inputBoard[i][j]);
  //   }
  //   printf("\n");
  // }
  // puts("\n\n");

  // make two types of board
  bool k = 0;
  for (int i = 0; i < 8; i++) {
    for (int j = 0; j < 8; j++, k = !k) {
      boardTypeA[i][j] = k;
    }
    k = !k;
  }

  k = 1;
  for (int i = 0; i < 8; i++) {
    for (int j = 0; j < 8; j++, k = !k) {
      boardTypeB[i][j] = k;
    }
    k = !k;
  }

  // compare brute force
  int boardTrimed[8][8];
  int res;
  int min;
  for (int x = 0; x <= n - 8; x++) {
    for (int y = 0; y <= m - 8; y++) {

      for (int k = 0, i = x; i < x + 8; k++, i++) {
        for (int l = 0, j = y; j < y + 8; l++, j++) {
          boardTrimed[k][l] = inputBoard[i][j];
        }
      }

      min = getMinDiff(boardTrimed);
      if (x == 0 && y == 0) {
        res = min;
      }
      if (res > min) {
        res = min;
      }
    }
  }

  printf("%d\n", res);

  return 0;
}