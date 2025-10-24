#include <bits/stdc++.h>
#include <queue>
using namespace std;

class Solution {
  private:
    int getDistance(vector<int>& a) {
      if (a.size() != 2) {
        return -1;
      }
      return a[0] * a[0] + a[1] * a[1];
    } 
  public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
      auto compare = [&](vector<int> a, vector<int> b) {
        return getDistance(a) < getDistance(b);
      };

      priority_queue<vector<int>, vector<vector<int>>, decltype(compare)> pq(compare);

      for (vector<int>& point : points) {
        pq.push(point);

        while (pq.size() > k) {
          pq.pop();
        }
      }

      vector<vector<int>> ans;

      while (!pq.empty()) {
        vector<int> point;
        point = pq.top();
        ans.push_back(point);
        pq.pop();
      }

      return ans;
    }
};

