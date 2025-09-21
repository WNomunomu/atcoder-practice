#include <bits/stdc++.h>
using namespace std;

int main() {
  string s;
  cin >> s;

  int count = 0;
  int maxCount = 0;

  for (int i = 0; i < s.length(); i++) {
    if (s[i] == 'A' || s[i] == 'T' || s[i] == 'G' || s[i] == 'C') {
      count++;
    }
    else {
      count = 0;
    }
    maxCount = max(maxCount, count);
  }

  cout << maxCount << endl;

  return 0;
}
