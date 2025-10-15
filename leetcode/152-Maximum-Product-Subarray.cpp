#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int maxProduct(vector<int>& nums) {
      int res = *max_element(nums.begin(), nums.end());
      int curMax = 1;
      int curMin = 1;

      for (int& num : nums) {
        int temp = curMax * num;

        curMax = max({ num, temp, curMin * num });
        curMin = min({ num, temp, curMin * num });

        res = max(res, curMax);
      }

      return res;
    }
};

