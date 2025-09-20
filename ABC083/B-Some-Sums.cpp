#include <bits/stdc++.h>
using namespace std;

int findSumOfDigits(int n) {
  int sum = 0;

  while (n > 0) {
    sum += n % 10;
    n = n / 10;
  }
  return sum;
}

int main() {
  int n, a, b;
  cin >> n >> a >> b;
  
  int ans = 0;

  for (int i = 1; i <= n; i++) {
    int sum = findSumOfDigits(i);
    if (sum >= a && sum <= b) {
      ans += i;
    }
  }

  cout << ans << endl;

  return 0;
}
