#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int coinChange(vector<int>& coins, int amount) {
      int maxValue = 100000;

      vector<int> dp(amount + 1, maxValue);
      dp[0] = 0;

      for (int i = 1; i <= amount; i++) {
        for (int& coin : coins) {
          if (i - coin >= 0 && dp[i - coin] != maxValue) {
            dp[i] = min(dp[i], dp[i - coin] + 1);
          }
        }
      }
      
      return dp[amount] == maxValue ? -1 : dp[amount];
    }
};

