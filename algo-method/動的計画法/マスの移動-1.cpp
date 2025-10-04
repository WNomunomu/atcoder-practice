#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> A(n);
  A[0] = 0;

  for (int i = 0; i < n; i++) {
    int a;
    cin >> a;

    if (i == 0) continue;
    else if (i == 1) {
      A[i] = A[i - 1] + a;
    }
    else {
      A[i] = min(A[i - 1] + a, A[i - 2] + a * 2);
    }
  }

  cout << A[n - 1] << endl;

  return 0;
}

