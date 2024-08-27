#include <iostream>
using namespace std;

int main() {

  int X;
  cin >> X;

  int i = 1;
  while (true) {
    if (X - i <= 0) {
      break;
    }

    X -= i++;
  }

  int sum = i + 1;

  if (sum % 2 == 0) {
    cout << sum - X << "/" << X << endl;
  } else {
    cout << X << "/" << sum - X << endl;
  }

  return 0;
}