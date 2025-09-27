#include <bits/stdc++.h>
using namespace std;

void bfs(
  int s, vector<vector<int>>& G, vector<bool>& isVisited, vector<int>& indeg, vector<int>& out
) {
  queue<int> q;
  q.push(s);
  isVisited[s] = true;
  
  while (!q.empty()) {
    int v = q.front();
    q.pop();
    out.push_back(v);

    for (int& vv : G[v]) {
      indeg[vv]--;
      if (indeg[vv] == 0 && !isVisited[vv]) {
        q.push(vv);
        isVisited[vv] = true;
      }
    }
  }
}

void topologicalSort(
  vector<vector<int>>& G, vector<bool>& isVisited, vector<int>& indeg, vector<int>& out
) {
  int n = G.size();

  for (int v = 0; v < n; v++) {
    for (int& vv : G[v]) {
      indeg[vv]++;
    }
  }

  for (int v = 0; v < n; v++) {
    if (indeg[v] == 0 && !isVisited[v]) {
      bfs(v, G, isVisited, indeg, out);
    }
  }

  for (int& number : out) {
    cout << number << endl;
  }
}

int main() {
  int n, e;
  cin >> n >> e;
  vector<vector<int>> G(n);

  for (int i = 0; i < e; i++) {
    int s, t;
    cin >> s >> t;
    G[s].push_back(t);
  }
  
  vector<bool> isVisited(n, false);
  vector<int> indeg(n, 0);
  vector<int> out;
  
  topologicalSort(G, isVisited, indeg, out);

  return 0;
}
