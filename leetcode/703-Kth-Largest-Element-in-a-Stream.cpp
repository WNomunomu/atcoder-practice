#include <bits/stdc++.h>
#include <queue>
using namespace std;

class KthLargest {
  private:
    int index;
    priority_queue<int, vector<int>, greater<int>> pq;
  public:
    KthLargest(int k, vector<int>& nums) {
      index = k;

      for (int& num : nums) {
        pq.push(num);
      }

      while (pq.size() > index) {
        pq.pop();
      }
    }
    
    int add(int val) {
      pq.push(val);

      while (pq.size() > index) {
        pq.pop();
      }
      
      return pq.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */

