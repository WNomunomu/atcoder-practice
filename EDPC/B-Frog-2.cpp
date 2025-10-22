#include <bits/stdc++.h>
#include <climits>
using namespace std;
#define int long long

signed main() {
  int n, k;
  cin >> n >> k;

  vector<int> H;

  for (int i = 0; i < n; i++) {
    int h;
    cin >> h;
    H.push_back(h);
  }

  vector<int> dp(n, INT_MAX);
  dp[0] = 0;

  for (int i = 1; i < n; i++) {
    for (int j = 1; j <= k; j++) {
      if (i - j >= 0) {
        dp[i] = min(dp[i], abs(H[i] - H[i - j]) + dp[i - j]);
      }
    }
  }

  cout << dp[n - 1] << endl;

  return 0;
}

