#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
  int s, a, b, x;
  cin >> s >> a >> b >> x;

  int ans = 0;

  while (x > 0) {
    if (a > x) {
      ans += s * x;
    }
    else {
      ans += s * a;
    }
    x -= a;
    x -= b;
  }

  cout << ans << endl;

  return 0;
}

