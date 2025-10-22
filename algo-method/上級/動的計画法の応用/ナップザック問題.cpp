#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
  int n, m;
  cin >> n >> m;

  vector<int> w(n);
  vector<int> v(n);

  for (int i = 0; i < n; i++) cin >> w[i];
  for (int i = 0; i < n; i++) cin >> v[i];

  vector<int> dp(m + 1, 0);
  dp[0] = 0;

  for (int i = 0; i < n; i++) {
    vector<int> temp = dp;
    for (int j = w[i]; j <= m; j++) {
      dp[j] = max(dp[j], temp[j - w[i]] + v[i]);
    }
  }

  int res = 0;

  for (int x : dp) {
    res = max(res, x);
  }

  cout << res << endl;

  return 0;
}

