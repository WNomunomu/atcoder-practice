#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
  int n;
  cin >> n;

  int a = 0;
  int b = 0;

  vector<int> w;
  int sum = 0;

  for (int i = 0; i < n; i++) {
    int weight;
    cin >> weight;
    sum += weight;
    w.push_back(weight);
  }

  vector<int> dp(sum + 1, false);
  dp[0] = true;

  for (int i = 0; i < n; i++) {
    for (int j = sum; j >= w[i]; j--) {
      if (dp[j - w[i]]) {
        dp[j] = true;
      }
    }
  }

  int ans = sum;

  for (int i = 0; i <= sum; i++) {
    if (dp[i]) {
      ans = min(ans, abs(sum - 2 * i));
    }
  }

  cout << ans << endl;

  return 0;
}

