#include <algorithm>
#include <iostream>
using namespace std;

bool compare(string a, string b) {
  if (a.length() != b.length()) {
    return a.length() < b.length();
  } else {
    return a < b;
  }
}

int main() {
  string str[20000];
  int n;
  cin >> n;

  for (unsigned int i = 0; i < n; i++) {
    cin >> str[i];
  }

  sort(str, str + n, compare);

  for (unsigned int i = 0; i < n; i++) {
    if (str[i] == str[i + 1]) {
      continue;
    }
    cout << str[i] << endl;
  }

  return 0;
}