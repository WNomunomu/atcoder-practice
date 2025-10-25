#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
      int n = temperatures.size();
      vector<int> ans(n, 0);

      stack<pair<int, int>> st;

      for (int i = 0; i < n; i++) {
        int current = temperatures[i];

        while (!st.empty() && st.top().second < current) {
          ans[st.top().first] = i - st.top().first;
          st.pop();
        }

        if (i == n - 1) break;

        int next = temperatures[i + 1];

        if (next > current) {
          ans[i] = 1;
        }
        else {
          st.push(make_pair(i, current));
        }
      }

      return ans;
    }
};

