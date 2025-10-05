#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;

  vector<int> dp(n);
  vector<int> temp(n);

  for (int i = 0; i < n; i++) {
    int a;
    cin >> a;
    temp[i] = a;
  }

  for (int i = n - 1; i >= 0; i--) {
    int a = temp[i];

    if (i == n - 1) {
      dp[i] = a;
    }
    else {
      dp[i] = dp[i + 1] + a;
    }
  }

  for (int i = 1; i < n; i++) {

    for (int j = 0; j < n; j++) {
      int a;
      cin >> a;
      temp[j] = a;
    }

    for (int j = n - 1; j >= 0; j--) {
      int a = temp[j];

      if (j == n - 1) {
        dp[j] += a;
      }
      else {
        dp[j] = min(dp[j + 1], dp[j]) + a;
      }
    }
  }

  cout << dp[0] << endl;

  return 0;
}
