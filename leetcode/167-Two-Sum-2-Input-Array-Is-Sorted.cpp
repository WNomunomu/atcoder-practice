#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

class Solution {
  public:
    vector<int> twoSum(vector<int>& numbers, int target) {
      unordered_map<int, int> map;

      vector<int> ans;

      for (int i = 0; i < numbers.size(); i++) {
        int num = numbers[i];
        if (map.contains(num)) {
          ans.push_back(map[num]);
          ans.push_back(i + 1);
        }
        else {
          map[target - num] = i + 1;
        }
      }

      return ans;
    }
};

