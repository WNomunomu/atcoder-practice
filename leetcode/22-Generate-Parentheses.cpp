#include <bits/stdc++.h>
using namespace std;

class Solution {
  private:
    void dfs(int open, int close, string parenthesis, int n, vector<string>& res) {
      if (open == close && open + close == n * 2) {
        res.push_back(parenthesis);
        return;
      }

      if (open < n) {
        dfs(open + 1, close, parenthesis + "(", n, res);
      }

      if (close < open) {
        dfs(open, close + 1, parenthesis + ")", n, res);
      }
    }
  public:
    vector<string> generateParenthesis(int n) {
      vector<string> res;
      dfs(0, 0, "", n, res);

      return res;
    }
};

