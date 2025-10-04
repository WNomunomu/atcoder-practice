#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;

  vector<int> A(n + 1, 0);
  A[0] = 1;

  for (int i = 1; i <= n; i++) {
    if (i - 1 >= 0) {
      A[i] += A[i - 1];
    }
    if (i - 2 >= 0) {
      A[i] += A[i - 2];
    }
  }

  cout << A[n] << endl;

  return 0;
}

