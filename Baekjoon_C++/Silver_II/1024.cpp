#include <iostream>
using namespace std;

void printSeries(int start, int length) {
  for (int i = start; i < start + length; i++) {
    cout << i << " ";
  }
  cout << endl;
}

int sumOfSeries(int a, int d, int n) { return n * (2 * a + (n - 1) * d) / 2; }

int main() {

  int sum, length;
  cin >> sum >> length;

  int i = 0;
  int l = length;
  int total;
  do {
    if (l > 100) {
      cout << -1 << endl;
      break;
    }

    i = int(sum / l) - int((l - 1) / 2);

    if (i >= 0 && sumOfSeries(i, 1, l) == sum) {
      printSeries(i, l);
      break;
    }

    l++;
  } while (true);

  return 0;
}