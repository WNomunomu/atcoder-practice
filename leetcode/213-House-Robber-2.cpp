#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int rob(vector<int>& nums) {
      if (nums.size() == 0) {
        return 0;
      }
      if (nums.size() == 1) {
        return nums[0];
      }
      vector<int> A(nums.begin(), nums.end() - 1);
      vector<int> B(nums.begin() + 1, nums.end());
      return max(getMax(A), getMax(B));
    }
  private:
    int getMax(vector<int>& nums) {
      int n = nums.size();
      vector<int> dp(n);

      if (n == 1) {
        return nums[0];
      }

      dp[0] = nums[0];
      dp[1] = max(nums[0], nums[1]);

      for (int i = 2; i < n; i++) {
        dp[i] = max(dp[i - 1], dp[i - 2] + nums[i]);
      }

      return dp[n - 1];
    }
};

