#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int evalRPN(vector<string>& tokens) {
      stack<string> S;

      set<string> operators = { "+", "-", "*", "/" };

      for (string& token : tokens) {
        if (operators.contains(token)) {
          int a = stoi(S.top());
          S.pop();
          int b = stoi(S.top());
          S.pop();
          if (token == "+") {
            int c = a + b;
            S.push(to_string(c));
          }                
          else if (token == "-") {
            int c = b - a;
            S.push(to_string(c));
          }
          else if (token == "*") {
            int c = a * b;
            S.push(to_string(c));
          }
          else if (token == "/") {
            int c = b / a;
            S.push(to_string(c));
          }
        }
        else {
          S.push(token);
        }
      }

      return stoi(S.top());
    }
};

