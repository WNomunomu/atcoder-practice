#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, k;
  cin >> n >> k;

  vector<int> A(n);
  vector<long long> S(n);

  for (int i = 0; i < n; i++) {
    cin >> A[i];
    if (i == 0) {
      S[i] = A[i];
    }
    else {
      S[i] = S[i - 1] + A[i];
    }
  }

  long long ans = 0;

  for (int i = 0; i < n - k + 1; i++) {
    if (i == 0) {
      long long sum = S[k - 1];
      ans += sum;
    }
    else {
      long long sum = S[i + k - 1] - S[i - 1];
      ans += sum;
    }
  }

  cout << ans << endl;

  return 0;
}
