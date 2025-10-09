#include <bits/stdc++.h>
#include <cwchar>
#include <unordered_map>
using namespace std;

int main() {
  int n;
  cin >> n;

  unordered_map<int, int> map;

  vector<int> A(n + 1);

  for (int i = 1; i <= n; i++) {
    int a;
    cin >> a;

    map[i + a]++;
    A[i] = a;
  }
  
  long long ans = 0;
  
  for (int j = 1; j <= n; j++) {
    ans += map[j - A[j]];
  }

  cout << ans << endl;
  
  return 0;
}

