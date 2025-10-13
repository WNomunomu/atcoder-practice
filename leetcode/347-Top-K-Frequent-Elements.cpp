#include <bits/stdc++.h>
#include <queue>
#include <unordered_map>
using namespace std;

class Solution {
  public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
      vector<int> ans;

      auto cmp = [](pair<int, int>& a, pair<int, int>& b) {
        return a.second < b.second;
      };

      priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)> pq(cmp);

      unordered_map<int, int> map;

      for (int& num : nums) {
        map[num]++;
      }

      for (auto& pair : map) {
        pq.push(pair);
      }

      for (int i = 0; i < k; i++) {
        ans.push_back(pq.top().first);
        pq.pop();
      }

      return ans;
    }
};

