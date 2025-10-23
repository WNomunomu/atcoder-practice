#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
  int n, a, b;
  cin >> n >> a >> b;

  vector<int> Cards;

  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    Cards.push_back(x);
  }

  int nil = -1;
  
  vector<bool> dp(a, false);
  dp[0] = true;

  for (int i = 0; i < n; i++) {
    vector<bool> prev = dp;
    int x = Cards[i];

    for (int j = 0; j < a; j++) {
      if (prev[j]) {
        int nextIndex = (j + x) % a;
        dp[nextIndex] = true;
      }
    }
  }

  cout << (dp[b] ? "Yes" : "No") << endl;

  return 0;
}

