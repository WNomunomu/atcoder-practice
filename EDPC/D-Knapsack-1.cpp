#include <bits/stdc++.h>
#include <cwchar>
using namespace std;
#define int long long

signed main() {
  int n, w;
  cin >> n >> w;

  vector<int> dp(w + 1, 0);

  for (int i = 0; i < n; i++) {
    int u, v;
    cin >> u >> v;

    vector<int> temp = dp;

    for (int j = u; j <= w; j++) {
      dp[j] = max(temp[j], temp[j - u] + v);
    }
  }

  int res = 0;

  for (int x : dp) {
    res = max(res, x);
  }

  cout << res << endl;

  return 0;
}

