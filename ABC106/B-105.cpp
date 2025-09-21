#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;

  vector<int> ans;

  for (int i = 1; i <= n; i+=2) {
    int count = 0;
    for (int j = 1; j <= n; j+=2) {
      if (i % j == 0) {
        count++;
      }
    } 
    if (count == 8) {
      ans.push_back(i);
    }
  }

  cout << ans.size() << endl;

  return 0;
}
