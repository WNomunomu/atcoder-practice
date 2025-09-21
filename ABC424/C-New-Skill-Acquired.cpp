#include <bits/stdc++.h>
#include <cmath>
using namespace std;

int main() {
  int n;
  cin >> n;

  vector<vector<int>> G(n + 1);

  for (int i = 1; i <= n; i++) {
    int a, b;
    cin >> a >> b;
    G[a].push_back(i);
    G[b].push_back(i);
  }

  vector<bool> isVisitedArray(n + 1);
  isVisitedArray[0] = true;

  auto dfs = [&](auto self, int v) -> void {
    isVisitedArray[v] = true;
    for (int vv : G[v]) {
      if (!isVisitedArray[vv]) {
        self(self, vv);
      }
    }
  };

  dfs(dfs, 0);

  int count = 0;

  for (bool isVisited : isVisitedArray) {
    count += isVisited;
  }

  cout << count - 1 << endl;

  return 0;
}
