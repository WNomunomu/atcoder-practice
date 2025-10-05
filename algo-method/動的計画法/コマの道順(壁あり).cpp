#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;

  vector<int> dp(n);

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      char c;
      cin >> c;

      if (c == '#') {
        dp[j] = 0;
      }
      else if (i == 0 && j == 0) {
        dp[j] = 1;
      }
      else {
        dp[j] += dp[j - 1];
      }
    }
  }

  cout << dp[n - 1] << endl;

  return 0;
}

