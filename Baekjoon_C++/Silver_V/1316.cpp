#include <iostream>
using namespace std;

bool isGroupWord(string str) {
  bool alphabet[26] = {
      false,
  };

  for (int i = 0; i < str.length(); i++) {

    if (i + 1 < str.length() && str[i] == str[i + 1]) {
      continue;
    }

    if (alphabet[str[i] - 'a'] == true) {
      return false;
    }

    alphabet[str[i] - 'a'] = true;
  }

  return true;
}

int main() {

  int N;
  cin >> N;

  string str[N];
  for (int i = 0; i < N; i++) {
    cin >> str[i];
  }

  int cnt = 0;
  for (int i = 0; i < N; i++) {
    isGroupWord(str[i]) && ++cnt;
  }

  cout << cnt << endl;

  return 0;
}