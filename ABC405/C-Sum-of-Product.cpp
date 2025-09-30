#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  
  vector<long long> A(n);

  for (int i = 0; i < n; i++) {
    cin >> A[i];
  }

  long long sum = 0;
  long long ans = 0;

  for (int i = 0; i < n; i++) {
    ans += A[i] * sum;
    sum += A[i];
  }

  cout << ans << endl;

  return 0;
}

