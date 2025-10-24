#include <bits/stdc++.h>
using namespace std;

class MinStack {
  private:
    vector<pair<int, int>> S;
    
  public:
    MinStack() {
       
    }
    
    void push(int val) {
      int minValue = S.empty() ? val : min(S.back().second, val);
      S.push_back({ val, minValue });
    }
    
    void pop() {
      if (!S.empty()) {
        S.pop_back();
      }
    }
    
    int top() {
      return S.back().first;
    }
    
    int getMin() {
      return S.back().second;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */

