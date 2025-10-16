#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    bool isValid(string s) {
      stack<char> S;

      for (char& c : s) {
        if (S.empty()) {
          S.push(c);
        }
        else {
          char top = S.top();

          if (isPair(top, c)) {
            S.pop();
          }
          else {
            S.push(c);
          }
        }
      }

      return S.empty();
    }
  private:
    bool isPair(char lastChar, char currentChar) {
      return (lastChar == '{' && currentChar == '}') ||
             (lastChar == '(' && currentChar == ')') ||
             (lastChar == '[' && currentChar == ']');
    }
};

