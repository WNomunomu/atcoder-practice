#include <algorithm>
#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
  int n;
  cin >> n;

  vector<int> dp(3);  

  int a, b, c;

  cin >> a >> b >> c;

  dp[0] = a;
  dp[1] = b;
  dp[2] = c;

  for (int i = 1; i < n; i++) {
    int a, b, c;
    cin >> a >> b >> c;

    vector<int> temp = dp;

    dp[0] = max(temp[1], temp[2]) + a;
    dp[1] = max(temp[0], temp[2]) + b;
    dp[2] = max(temp[0], temp[1]) + c;
  }

  cout << *max_element(dp.begin(), dp.end()) << endl;

  return 0;
}

