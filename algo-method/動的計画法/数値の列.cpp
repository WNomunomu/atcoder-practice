#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, x, y;
  cin >> n >> x >> y;

  vector<int> A(n);

  A[0] = x;
  A[1] = y;

  for (int i = 2; i < n; i++) {
    A[i] = (A[i - 2] + A[i - 1]) % 100;
  }
  
  cout << A[n - 1] << endl;
  return 0;
}

