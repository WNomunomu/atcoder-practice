#include <bits/stdc++.h>
#include <queue>
using namespace std;

class Solution {
  public:
    int findKthLargest(vector<int>& nums, int k) {
      priority_queue<int, vector<int>, greater<>> pq;

      for (int& num : nums) {
        pq.push(num);

        while (pq.size() > k) {
          pq.pop();
        }
      }

      return pq.top();
    }
};

