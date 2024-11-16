#include <algorithm>
#include <cstring>
#include <iostream>

#define MAX 1000000
#define LEN 20

using namespace std;

bool lexicographicalCompare(string word1, string word2) {
  if (word1.length() != word2.length()) {
    return min(word1.length(), word2.length());
  } else {
    return word1.compare(word2);
  }
}

int main() {

  int n;
  cin >> n;

  char wordList[n][LEN];
  for (int i = 0; i < n; i++) {
    cin >> wordList[i];
  }

  return 0;
}