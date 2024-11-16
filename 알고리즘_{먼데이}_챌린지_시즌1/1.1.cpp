#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

bool lexicoCmp(string word1, string word2) {
  if (word1.length() != word2.length()) {
    return word1.length() < word2.length();
  } else {
    return word1.compare(word2) < 0;
  }
}

int main() {

  int n;
  int index;
  cin >> n >> index;

  vector<string> wordList(1000000);
  for (int i = 0; i < n; i++) {
    cin >> wordList[i];
  }

  sort(wordList.begin(), wordList.begin() + n, lexicoCmp);

  cout << endl;
  for (int i = 0; i < n; i++) {
    cout << wordList[i] << endl;
  }

  cout << wordList.at(index - 1) << endl;

  return 0;
}