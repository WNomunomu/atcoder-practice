#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
      vector<vector<int>> G(numCourses);
      vector<int> deg(numCourses, 0);

      for (vector<int>& prerequisite : prerequisites) {
        G[prerequisite[1]].push_back(prerequisite[0]);
        deg[prerequisite[0]]++;
      }

      vector<bool> isVisited(numCourses, false);

      vector<int> ans;

      auto dfs = [&](auto self, int u) -> void {
        isVisited[u] = true;
        ans.push_back(u);

        for (int& v : G[u]) {
          deg[v]--;

          if (deg[v] == 0 && !isVisited[v]) {
            self(self, v);
          }
        }
      };

      for (int i = 0; i < numCourses; i++) {
        if (deg[i] == 0 && !isVisited[i]) {
          dfs(dfs, i);
        }
      }

      for (bool x : isVisited) {
        if (!x) {
          return {};
        }
      }

      return ans;
    }
};

