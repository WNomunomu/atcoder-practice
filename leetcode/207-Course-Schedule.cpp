#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
      vector<bool> isVisited(numCourses, false);
      
      vector<vector<int>> G(numCourses);
      vector<int> deg(numCourses, 0);

      for (vector<int>& prerequisite : prerequisites) {
        G[prerequisite[1]].push_back(prerequisite[0]);
        deg[prerequisite[0]]++;
      }

      vector<bool> isStartNode(numCourses, false);

      int count = 0;

      auto dfs = [&](auto self, int u) -> void {
        count++;
        isVisited[u] = true;

        for (int& v : G[u]) {
          deg[v]--;
          if (!isVisited[v] && deg[v] == 0) {
            self(self, v);
          }
        }
      };

      for (int i = 0; i < numCourses; i++) {
        if (deg[i] == 0) {
          isStartNode[i] = true;
        }
      }

      for (int i = 0; i < numCourses; i++) {
        if (isStartNode[i]) {
          dfs(dfs, i);
        }
      }

      bool ans;

      if (count == numCourses) {
        return true;
      }
      else {
        return false;
      }
    }
};

