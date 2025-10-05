#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, m;
  cin >> n >> m;

  vector<int> D;
  vector<int> isEnableToVisit(n + 1, false);
  
  isEnableToVisit[0] = true;

  for (int i = 0; i < m; i++) {
    int d;
    cin >> d;
    D.push_back(d);
  }

  for (int i = 1; i <= n; i++) {
    for (int j = 0; j < m; j++) {
      if (i - D[j] >= 0) {
        isEnableToVisit[i] = isEnableToVisit[i] || isEnableToVisit[i - D[j]];
      }
    }
  }

  if (isEnableToVisit[n]) {
    cout << "Yes" << endl;
  }
  else {
    cout << "No" << endl;
  }
  
  return 0;
}

