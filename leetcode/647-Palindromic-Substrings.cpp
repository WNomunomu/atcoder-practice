#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int countSubstrings(string s) {
      int ans = 0;

      for (int i = 0; i < s.length(); i++) {
        ans += countParindrome(s, i, i);
        ans += countParindrome(s, i, i + 1);
      }

      return ans;
    }
  private:
    int countParindrome(string s, int start, int end) {
      int count = 0;

      while (start >= 0 && end < s.length() && s[start] == s[end]) {
        count++;
        start--;
        end++;
      }

      return count;
    }
};

