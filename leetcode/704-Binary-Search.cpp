#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int search(vector<int>& nums, int target) {
      int n = nums.size();

      int ng = -1;
      int ok = n;

      while (ok - ng > 1) {
        int mid = (ok + ng) / 2;

        if (nums[mid] == target) {
          return mid;
        }
        else if (nums[mid] > target) {
          ok = mid;
        }
        else {
          ng = mid;
        }
      }

      return -1;
    }
};

