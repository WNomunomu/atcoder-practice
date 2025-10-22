#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
  int n, m;
  cin >> n >> m;

  int nil = -1;

  vector<int> dp(m + 1, INT_MAX);
  dp[0] = 0;

  for (int i = 0; i < n; i++) {
    int w;
    cin >> w;

    vector<int> temp = dp;

    for (int j = w; j <= m; j++) {
      if (temp[j - w] != nil) {
        dp[j] = min(temp[j - w] + 1, temp[j]);
      }
    }
  }

  if (dp[m] == INT_MAX) {
    cout << nil << endl;
  }
  else {
    cout << dp[m] << endl;
  }

  return 0;
}

