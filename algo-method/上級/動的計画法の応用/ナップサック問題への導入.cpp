#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
  int n, m;
  cin >> n >> m;

  vector<int> A;
  vector<int> B;

  for (int i = 0; i < n - 1; i++) {
    int a;
    cin >> a;
    A.push_back(a);
  }

  for (int i = 0; i < n - 1; i++) {
    int b;
    cin >> b;
    B.push_back(b);
  }

  vector<int> dp(m, -1);
  dp[0] = 0;

  for (int i = 0; i < n - 1; i++) {
    int a = A[i];
    int b = B[i];

    vector<int> temp = dp;

    for (int j = 0; j < m; j++) {
      if (temp[j] != -1 && j + a < m) {
        dp[j + a] = max(dp[j + a], temp[j] + b);
      }
    }
  }
  
  cout << dp[m - 1] << endl;

  return 0;
}

