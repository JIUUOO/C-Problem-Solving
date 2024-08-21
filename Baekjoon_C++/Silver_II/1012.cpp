#include <iostream>
using namespace std;

#define ROW 50
#define COL 50
#define NUM 2500

class Farm {
private:
  int row;
  int col;
  int num;
  int farm[ROW][COL];

public:
  Farm(int row, int col, int num) : row(row), col(col), num(num) {
    for (int i = 0; i < row; i++) {
      for (int j = 0; j < col; j++) {
        farm[i][j] = 0;
      }
    }
  };
  void setFarmData() {
    int posX, posY;
    for (int i = 0; i < num; i++) {
      cin >> posX >> posY;
      farm[posY][posX] = 1;
    }
  }

  int getWormNum() {
    int cnt = 0;
    for (int i = 0; i < row; i++) {
      for (int j = 0; j < col; j++) {
        removeCabbage(i, j) && cnt++;
      }
    }
    return cnt;
  }

  bool removeCabbage(int i, int j) {
    if (farm[i][j] == 1) {
      farm[i][j] = 0;
      if (i - 1 >= 0 && farm[i - 1][j] == 1) {
        removeCabbage(i - 1, j);
        farm[i - 1][j] = 0;
      }
      if (i + 1 < row && farm[i + 1][j] == 1) {
        removeCabbage(i + 1, j);
        farm[i + 1][j] = 0;
      }

      if (j - 1 >= 0 && farm[i][j - 1] == 1) {
        removeCabbage(i, j - 1);
        farm[i][j - 1] = 0;
      }

      if (j + 1 < col && farm[i][j + 1] == 1) {
        removeCabbage(i, j + 1);
        farm[i][j + 1] = 0;
      }
      return true;
    }
    return false;
  }
};

int main() {

  int test = 0;
  cin >> test;

  int res[test];

  for (int i = 0; i < test; i++) {
    int col, row, num;
    cin >> col >> row >> num;
    Farm farm(row, col, num);
    farm.setFarmData();

    res[i] = farm.getWormNum();
  }

  for (int i = 0; i < test; i++) {
    cout << res[i] << endl;
  }

  return 0;
}