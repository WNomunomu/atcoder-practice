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

  vector<int> isVisited(n + 1, false);
  queue<int> q;
  q.push(1);
  vector<int> distanceArray(n + 1, -1);
  isVisited[1] = true;

  int distance = 0;
  distanceArray[1] = 0; 

  while(!q.empty()) {
    int v = q.front();
    q.pop();

    for (int vv : G[v]) {
      if (!isVisited[vv]) {
        isVisited[vv] = true;
        distanceArray[vv] = distanceArray[v] + 1;
        q.push(vv);
      }
    }
  }

  for (int i = 1; i <= n; i++) {
    cout << i << " " << distanceArray[i] << endl; 
  }

  return 0;
}
