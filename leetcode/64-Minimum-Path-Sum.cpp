#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int minPathSum(vector<vector<int>>& grid) {
      int maxValue = 10000000;
      int m = grid.size();
      int n = grid[0].size();
      vector<int> dp(m, maxValue);
      dp[0] = grid[0][0];

      for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
          if (j == 0) {
            if (i != 0) {
              dp[j] += grid[j][i];
            }
          }
          else {
            dp[j]= min(dp[j - 1], dp[j]) + grid[j][i];
          }
        }
      }

      return dp[m - 1];
    }
};

