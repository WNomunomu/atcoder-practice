#include <bits/stdc++.h>
#include <climits>
using namespace std;

int main() {
  int n, m;
  cin >> n >> m;

  vector<int> A(n);
  A[0] = 0;

  for (int i = 0; i < n; i++) {
    int a;
    cin >> a;

    if (i == 0) {
      continue;
    }

    int time = INT_MAX;

    for (int j = 1; j <= m; j++) {
      if (i - j >= 0) {
        time = min(time, A[i - j] + a * j);
      }
    }

    A[i] = time;
  }

  cout << A[n - 1] << endl;

  return 0;
}
