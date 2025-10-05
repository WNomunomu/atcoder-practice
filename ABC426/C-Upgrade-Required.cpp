#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, q;
  cin >> n >> q;

  vector<int> pc(n + 1, 1);

  int o = 1;

  for (int i = 0; i < q; i++) {
    int x, y;
    cin >> x >> y;

    int res = 0;

    for (; o <= x; o++) {
      pc[y] += pc[o];
      res += pc[o];
    }

    cout << res << endl;
  }

  return 0;
}

