#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
  int n;
  cin >> n;

  vector<int> H;

  for (int i = 0; i < n; i++) {
    int h;
    cin >> h;
    H.push_back(h);
  }

  vector<int> dp(n + 1);
  dp[0] = 0;
  dp[1] = abs(H[0] - H[1]);

  for (int i = 2; i < n; i++) {
    dp[i] = min(abs(H[i] - H[i - 1]) + dp[i - 1], abs(H[i] - H[i - 2]) + dp[i - 2]);
  }

  cout << dp[n - 1] << endl;

  return 0;
}

