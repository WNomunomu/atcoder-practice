#include <bits/stdc++.h>
#include <climits>
using namespace std;

int prim(vector<vector<int>>& G, int n) {
  vector<bool> isVisited(n, false);
  vector<int> minCost(n, INT_MAX);

  minCost[0] = 0;
  int totalWeight = 0;

  for (int i = 0; i < n; i++) {
    int u = -1;
    for (int j = 0; j < n; j++) {
      if (!isVisited[j]) { 
        if (u == -1 || minCost[j] < minCost[u]) {
          u = j;
        }
      }
    }
    
    isVisited[u] = true;
    totalWeight += minCost[u];

    for (int v = 0; v < n; v++) {
      if (!isVisited[v]) {
        if (G[u][v] != -1 && G[u][v] < minCost[v]) {
          minCost[v] = G[u][v];
        }
      }
    }
  }

  return totalWeight;
}

int main() {
  int n;
  cin >> n;

  vector<vector<int>> G(n);

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      int a;
      cin >> a;
      G[i][j] = a; 
    }
  }

  int result = prim(G, n);
  cout << result << endl;

  return 0;
}

