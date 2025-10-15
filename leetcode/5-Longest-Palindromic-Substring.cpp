#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    string longestPalindrome(string s) {
      if (s.empty()) {
        return "";
      }

      int start = 0;
      int end = 0;

      for (int i = 0; i < s.length(); i++) {
        int odd = expandAroundCenter(s, i, i);
        int even = expandAroundCenter(s, i, i + 1);
        int maxLen = max(odd, even);

        if (maxLen > end - start) {
          int start = i - (maxLen - 1) / 2;
          int end = i - maxLen / 2;
        }
      }

      return s.substr(start, end - start + 1);
    }
  private:
    int expandAroundCenter(string s, int start, int end) {
      while (start >= 0 && end < s.length() && s[start] == s[end]) {
        start--;
        end++;
      }
      return end - start - 1;
    }
};

