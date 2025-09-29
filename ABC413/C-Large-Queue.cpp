#include <bits/stdc++.h>
#include <utility>
using namespace std;

int main() {
  int n;
  cin >> n;

  queue<pair<int, int>> q;
  
  for (int i = 0; i < n; i++) {
    int query;
    cin >> query;

    if (query == 1) {
      int c, x;
      cin >> c >> x;
      q.push(make_pair(x, c));
    }
    else if (query == 2) {
      int k;
      cin >> k;
      long long ans = 0;
      
      while (k > 0) {
        if (q.front().second > k) {
          q.front().second -= k;
          ans += (long long)q.front().first * k;
          break;
        }
        else {
          ans += (long long)q.front().first * q.front().second;
          k -= q.front().second;
          q.pop();
        }
      }
      cout << ans << endl;
    }
  }

  return 0;
}
