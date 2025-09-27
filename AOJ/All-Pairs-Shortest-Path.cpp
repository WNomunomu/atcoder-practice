#include <bits/stdc++.h>
#include <climits>
using namespace std;

void warshallFloyd(vector<vector<int>>& Distance) {
  int n = Distance.size();

  for (int k = 0; k < n; k++) {
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        if (Distance[i][k] != INT_MAX && Distance[k][j] != INT_MAX) {
          Distance[i][j] = min(Distance[i][j], Distance[i][k] + Distance[k][j]);
        }
      }
    }
  }
}

int main() {
  int n, e;
  cin >> n >> e;

  vector<vector<int>> Distance(n, vector<int>(n, INT_MAX));

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (i == j) {
        Distance[i][j] = 0;
      }
    }
  }

  for (int i = 0; i < e; i++) {
    int s, t, d;
    cin >> s >> t >> d;
    Distance[s][t] = d;
  }

  warshallFloyd(Distance);

  bool haveNegativeCycle = false;

  for (int i = 0; i < n; i++) {
    if (Distance[i][i] < 0) {
      haveNegativeCycle = true;
      break;
    }
  }

  if (haveNegativeCycle) {
    cout << "NEGATIVE CYCLE" << endl;
  }
  else {
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        if (j != 0) cout << " ";
        if (Distance[i][j] == INT_MAX) {
          cout << "INF";
        }
        else {
          cout << Distance[i][j];
        }
      }
      cout << endl; 
    }
  }

    

  return 0;
}
