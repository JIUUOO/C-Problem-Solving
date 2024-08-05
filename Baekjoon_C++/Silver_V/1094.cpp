#include <iostream>
using namespace std;

inline int binaryOneCnt(int n) {
  int cntOne = 0;
  for (size_t i = 0; n != 0; i++) {
    (n % 2 == 1) && cntOne++;
    n /= 2;
  }

  return cntOne;
}

int main() {
  int x;

  cin >> x;

  cout << binaryOneCnt(x) << endl;

  return 0;
}