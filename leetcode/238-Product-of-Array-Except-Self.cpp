#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    vector<int> productExceptSelf(vector<int>& nums) {
      int zeroCount = 0;
      int allProduct = 1;
      int allProductExceptZero = 1;

      for (int& num : nums) {
        if (num == 0) zeroCount++;
        else {
          allProductExceptZero *= num;
        }
        allProduct *= num;
      }

      if (zeroCount > 1) {
        return vector<int>(nums.size(), 0);
      }
      else if (zeroCount == 1) {
        vector<int> ans;

        for (int& num : nums) {
          if (num == 0) {
            ans.push_back(allProductExceptZero);
          }
          else {
            ans.push_back(0);
          }
        }

        return ans;
      }
      else {
        vector<int> ans;

        for (int& num : nums) {
          ans.push_back(allProduct / num);
        }

        return ans;
      }
    }
};

