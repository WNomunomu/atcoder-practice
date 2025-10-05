#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;

  vector<int> dp(n);
  
  for (int i = 0; i < n; i++) {
    int a;
    cin >> a;
    if (i == 0) {
      dp[i] = a;
    }
    else {
      dp[i] = dp[i - 1] + a;
    }
  }

  for (int i = 1; i < n; i++) {
    for (int j = 0; j < n; j++) {
      int a;
      cin >> a;

      if (j == 0) {
        dp[j] += a;
      }
      else {
        dp[j] = max(dp[j], dp[j - 1]) + a;
      }
    }
  }

  cout << dp[n - 1] << endl;

  return 0;
}

