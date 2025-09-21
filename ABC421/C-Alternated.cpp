#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  string s;
  cin >> s;

  bool isAlternated = true;
  char prev = s[0];
  int count = 0;

  while (isAlternated) {
    bool isContinuous = false;

    for (int i = 1; i < s.length(); i++) {
      char cur = s[i];
      if (prev == cur) {
        isContinuous = true;
      }
      if (isContinuous && prev != cur) {
        char temp = prev;
        s[i - 1] = cur;
        s[i] = temp;
        isAlternated = true;
      }
      prev = s[i];
    }
     
  }

  return 0;
}
