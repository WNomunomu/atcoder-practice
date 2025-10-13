#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int maxArea(vector<int>& height) {
      int j = 0;
      int k = height.size() - 1;

      int ans = min(height[k], height[j]) * (k - j);

      for (int i = 0; i < height.size(); i++) {
        if (j == k) break;

        if (height[j] < height[k]) {
          j++;
        }
        else {
          k--;
        }

        int currentArea = min(height[k], height[j]) * (k - j);

        ans = max(ans, currentArea);
      }

      return ans;
    }
};

