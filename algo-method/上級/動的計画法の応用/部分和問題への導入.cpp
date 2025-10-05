#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, m;
  cin >> n >> m;

  vector<bool> dp(m, false);
  dp[0] = true;

  for (int i = 1; i < n; i++) {
    int a;
    cin >> a;

    vector<bool> temp = dp;

    for (int j = 0; j < m; j++) {
      if (temp[j] && j + a < m) {
        dp[j + a] = true;
      }
    }
  }

  int res = 0;

  for (bool isVisitable : dp) {
    if (isVisitable) res++;
  }

  cout << res << endl;

  return 0;
}

