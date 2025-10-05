#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, m;
  cin >> n >> m;

  vector<vector<int>> G(n);

  for (int i = 0; i < m; i++) {
    int a, b;
    cin >> a >> b;
    a--;
    b--;

    G[a].push_back(b);
    G[b].push_back(a);
  }

  vector<bool> isVisited(n, false);

  auto dfs = [&](auto self, int u) -> void {
    isVisited[u] = true;

    for (int& v : G[u]) {
      if (!isVisited[v]) {
        self(self, v);
      }
    }
  };

  dfs(dfs, 0);

  for (int i = 0; i < n; i++) {
    if (!isVisited[i] || G[i].size() != 2) {
      cout << "No" << endl;
      return 0;
    }
  }

  cout << "Yes" << endl;

  return 0;
}

