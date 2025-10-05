#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;

  vector<int> dp(n, 1);

  for (int i = 1; i < n; i++) {
    for (int j = 1; j < n; j++) {
      dp[j] += dp[j - 1];
    }
  }

  cout << dp[n - 1] << endl;

  return 0;
}

