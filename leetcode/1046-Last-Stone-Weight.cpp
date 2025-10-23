#include <bits/stdc++.h>
#include <queue>
using namespace std;

class Solution {
  private:
    priority_queue<int> pq;
  public:
    int lastStoneWeight(vector<int>& stones) {
      for (int& stone : stones) {
        pq.push(stone);
      }

      while (pq.size() > 1) {
        int heaviest = pq.top();
        pq.pop();
        int secondHeaviest = pq.top();
        pq.pop();

        if (heaviest - secondHeaviest > 0) {
          pq.push(heaviest - secondHeaviest);
        }
      }

      if (pq.empty()) {
        return 0;
      }
      else {
        return pq.top();
      }
    }
};

