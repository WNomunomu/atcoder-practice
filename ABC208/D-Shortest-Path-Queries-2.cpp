#include <bits/stdc++.h>
#include <climits>
using namespace std;

void warshallFloyd(vector<vector<int>>& Dist, int maxK, long long& count) {
  int n = Dist.size();
  
  for (int k = 0; k < maxK; k++) {
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        if (Dist[i][k] != INT_MAX && Dist[k][j] != INT_MAX) {
          Dist[i][j] = min(Dist[i][j], Dist[i][k] + Dist[k][j]);
        }
      }
    }

    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        if (Dist[i][j] != INT_MAX) {
          count += Dist[i][j];
        }
      }
    }
  }
}

int main() {
  int n, m;
  cin >> n >> m;

  vector<vector<int>> Dist(n, vector<int>(n, INT_MAX));

  for (int i = 0; i < n; i++) {
    Dist[i][i] = 0;
  }

  for (int i = 0; i < m; i++) {
    int a, b, c;
    cin >> a >> b >> c;
    Dist[a - 1][b - 1] = c;
  }

  long long count = 0;

  warshallFloyd(Dist, n, count);
  cout << count << endl;

  return 0;
}

