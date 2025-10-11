#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int rob(vector<int>& nums) {
      int n = nums.size();
      vector<int> dp(n + 1);
      dp[0] = 0;

      for (int i = 1; i <= n; i++) {
        int a = nums[i - 1];
        if (i == 1) {
          dp[i] = a;
        }
        else {
          dp[i] = max(dp[i - 1], dp[i - 2] + a);
        }
      }

      return dp[n];
    };
};

