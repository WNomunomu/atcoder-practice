#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;

  vector<vector<int>> G(n + 1);
  for (int i = 0; i < n; i++) {
    int u, k;
    cin >> u >> k;
    for (int j = 0; j < k; j++) {
      int v;
      cin >> v;
      G[u].push_back(v);
    }
  }

  vector<int> discoverTime(n + 1);
  vector<int> searchFinishedTime(n + 1);
  vector<bool> isVisited(n + 1);

  int time = 0;

  auto dfs = [&](auto self, int v) -> void {
    time++;
    isVisited[v] = true;
    discoverTime[v] = time; 
    
    for (int vv : G[v]) {
      if (!isVisited[vv]) {
        self(self, vv);
      }
    }
    
    time++;
    searchFinishedTime[v] = time;
  };

  for (int i = 1; i <= n; i++) {
    if (!isVisited[i]) {
      dfs(dfs, i);
    }
  }

  for (int i = 1; i <= n; i++) {
    cout << i << " " << discoverTime[i] << " " << searchFinishedTime[i] << endl; 
  }

  return 0;
}
