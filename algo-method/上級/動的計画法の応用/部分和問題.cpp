#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, m;
  cin >> n >> m;

  vector<int> dp(m + 1, false);
  dp[0] = true;

  for (int i = 0; i < n; i++) {
    int w;
    cin >> w;

    for (int j = 0; j <= m; j++) {
      if (dp[j]) {
        if (j + w <= m) {
          dp[j + w] = true;
        }
      }
    }
  }

  if (dp[m]) {
    cout << "Yes" << endl;
  }
  else {
    cout << "No" << endl;
  }

  return 0;
}

