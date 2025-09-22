#include <bits/stdc++.h>
#include <climits>
using namespace std;

static const int NIL = -1;

int prim(vector<vector<int>>& G, int n) {
  vector<bool> isVisited(n, false);
  vector<int> minCost(n, INT_MAX);

  minCost[0] = 0;
  int totalWeight = 0;

  for (int i = 0; i < n; i++) {
    int u = NIL;
    for (int j = 0; j < n; j++) {
      if (!isVisited[j]) { 
        if (u == NIL || minCost[j] < minCost[u]) {
          u = j;
        }
      }
    }

    if (u == NIL) {
      break;
    }
    
    isVisited[u] = true;
    totalWeight += minCost[u];

    for (int v = 0; v < n; v++) {
      if (!isVisited[v]) {
        if (G[u][v] != NIL && G[u][v] < minCost[v]) {
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

  vector<vector<int>> G(n, vector<int>(n));

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

