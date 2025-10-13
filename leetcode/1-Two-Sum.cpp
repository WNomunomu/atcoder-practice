#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

class Solution {
  public:
    vector<int> twoSum(vector<int>& nums, int target) {
      unordered_map<int, int> map;

      vector<int> ans;

      for (int i = 0; i < nums.size(); i++) {
        int num = nums[i];
        if (!map.contains(num)) {
          map[target - num] = i; 
        }
        else {
          ans.push_back(map[num]);
          ans.push_back(i);
          break;
        }
      }

      return ans;
    }
};

