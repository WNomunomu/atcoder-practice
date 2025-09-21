#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, m, k;
  cin >> n >> m >> k;

  vector<int> count(n);

  bool flag = false;
  for (int i = 0; i < k; i++) {
    int a, b;
    cin >> a >> b;
    
    count[a - 1]++;
    if (flag) {
      cout << " ";
    }
    if (count[a - 1] == m) {
      cout << a;
      flag = true;
    }
  }

  if (flag) {
    cout << endl;
  }
  return 0;
}
