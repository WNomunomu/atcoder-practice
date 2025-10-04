#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;

  vector<int> T(n + 1, 0);
  T[0] = 1;

  for (int i = 1; i <= n; i++) {
    if (i - 1 >= 0) T[i] += T[i - 1];
    if (i - 2 >= 0) T[i] += T[i - 2];
    if (i - 3 >= 0) T[i] += T[i - 3];
  }

  cout << T[n] << endl;

  return 0;
}

