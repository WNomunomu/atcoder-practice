#include <bits/stdc++.h>
using namespace std;

class Solution {
  private:
    vector<int> parent;

    int findTopParent(int x) {
      if (x == parent[x]) return x;

      int topParent = findTopParent(parent[x]); 

      return topParent;
    }

    bool unite(int x, int y) {
      int px = findTopParent(x);
      int py = findTopParent(y);

      if (px == py) return true;

      parent[px] = py;
      return false;
    }

  public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
      int n = edges.size();
      parent.resize(n + 1);

      for (int i = 1; i <= n; i++) {
        parent[i] = i;
      }

      for (vector<int>& edge : edges) {
        bool isUnited = unite(edge[0], edge[1]);

        if (isUnited) {
          return edge;
        }
      }

      return {};
    }
};

