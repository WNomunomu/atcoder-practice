#include <bits/stdc++.h>
#include <cctype>
using namespace std;

class Solution {
  public:
    bool isPalindrome(string s) {
      string t;

      for (char& c : s) {
        if (isalnum(c)) {
          t += tolower(c);
        }
      }

      if (t.size() == 0) return true;

      for (int i = 0; i < t.size() / 2; i++) {
        if (t[i] != t[t.size() - i - 1]) return false;
      }

      return true;
    }
};

