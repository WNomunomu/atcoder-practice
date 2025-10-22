#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
  int n, m;
  cin >> n >> m;

  vector<int> dp(m + 1, 0);
  dp[0] = 1;

  for (int i = 0; i < n; i++) {
    int a;
    cin >> a;

    vector<int> temp = dp;

    for (int j = a; j <= m; j++) {
      if (temp[j - a] != 0) {
        dp[j] = (temp[j] + temp[j - a]) % 1000;
      }
    }
  }

  cout << dp[m] << endl;

  return 0;
}

