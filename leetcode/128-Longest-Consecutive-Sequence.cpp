#include <bits/stdc++.h>
#include <queue>
using namespace std;

class Solution {
  public:
    int longestConsecutive(vector<int>& nums) {

      if (nums.size() == 0) return 0;

      priority_queue<int, vector<int>, greater<int>> pq;

      int ans = 1;
      int tempAns = 1;

      set<int> st(nums.begin(), nums.end());

      for (auto& num : st) {
        pq.push(num);
      }

      int prev = pq.top();
      pq.pop();

      while (!pq.empty()) {
        int num = pq.top();
        pq.pop();

        if (prev + 1 == num) {
          tempAns++;
        }
        else {
          tempAns = 1;
        }

        prev = num;

        ans = max(ans, tempAns);
      }

      return ans;
    }
};

