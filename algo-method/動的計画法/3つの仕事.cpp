#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;

  vector<int> dp;

  for (int i = 0; i < n; i++) {
    int a, b, c;
    cin >> a >> b >> c;

    if (i == 0) {
      dp.push_back(a);
      dp.push_back(b);
      dp.push_back(c);
      continue;
    }
    else {
      vector<int> temp = dp;
      
      dp[0] = max(temp[2], temp[1]) + a;
      dp[1] = max(temp[0], temp[2]) + b;
      dp[2] = max(temp[1], temp[0]) + c;
    }
  }

  int res = 0;

  for (int x : dp) {
    res = max(res, x);
  }

  cout << res << endl;

  return 0;
}

