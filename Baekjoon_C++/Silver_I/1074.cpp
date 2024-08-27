#include <iostream>
#include <math.h>
using namespace std;

void recursive(int N, const int r, const int c, int i, int j, int &cnt) {

  if (N == 1) {

    if (i == r && j == c) {
      cout << cnt << endl;
    }
    // cout << i << ", " << j << ": " << cnt++ << endl;
    cnt++;

    if (i == r && j + 1 == c) {
      cout << cnt << endl;
    }
    // cout << i << ", " << j + 1 << ": " << cnt++ << endl;
    cnt++;

    if (i + 1 == r && j == c) {
      cout << cnt << endl;
    }
    // cout << i + 1 << ", " << j << ": " << cnt++ << endl;
    cnt++;

    if (i + 1 == r && j + 1 == c) {
      cout << cnt << endl;
    }
    // cout << i + 1 << ", " << j + 1 << ": " << cnt++ << endl;
    cnt++;

    return;
  }

  if ((r >= i && r < i + pow(2, N - 1)) && (c >= j && c < j + pow(2, N - 1))) {
    recursive(N - 1, r, c, i, j, cnt);
  } else {
    cnt += pow(4, N - 1);
    // cout << cnt << endl;
  }

  if ((r >= i && r < i + pow(2, N - 1)) && (c >= j + pow(2, N - 1))) {
    recursive(N - 1, r, c, i, j + pow(2, N - 1), cnt);
  } else {
    cnt += pow(4, N - 1);
    // cout << cnt << endl;
  }

  if ((r >= i + pow(2, N - 1)) && (c >= j && c < j + pow(2, N - 1))) {
    recursive(N - 1, r, c, i + pow(2, N - 1), j, cnt);
  } else {
    cnt += pow(4, N - 1);
    // cout << cnt << endl;
  }

  if ((r >= i + pow(2, N - 1)) && (c >= j + pow(2, N - 1))) {
    recursive(N - 1, r, c, i + pow(2, N - 1), j + pow(2, N - 1), cnt);
  } else {
    cnt += pow(4, N - 1);
    // cout << cnt << endl;
  }
}

void getIndex(int N, int r, int c) {
  int cnt = 0;

  recursive(N, r, c, 0, 0, cnt);
}

int main() {

  int N, r, c;
  cin >> N >> r >> c;

  getIndex(N, r, c);

  return 0;
}