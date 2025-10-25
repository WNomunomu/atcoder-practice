#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
      int m = heights.size();
      int n = heights[0].size();

      vector<vector<bool>> pacific(m, vector<bool>(n, false));
      vector<vector<bool>> atlantic(m, vector<bool>(n, false));

      vector<vector<int>> res;

      vector<pair<int, int>> directions = {{ 0, 1 }, { 1, 0 }, { -1, 0 }, { 0, -1 }};

      auto dfs = [&](auto self, int r, int c, vector<vector<bool>>& isVisited) -> void {
        isVisited[r][c] = true;

        for (pair<int, int>& direction : directions) {
          int nr = r + direction.first;
          int nc = c + direction.second;

          if (nr >= 0 && nr < m && nc >= 0 && nc < n) {
            if (heights[nr][nc] >= heights[r][c] && !isVisited[nr][nc]) {
              self(self, nr, nc, isVisited);
            }
          }
        }
      };

      for (int r = 0; r < m; r++) {
        for (int c = 0; c < n; c++) {
          if (r == 0 || c == 0) {
            dfs(dfs, r, c, pacific);
          }
          if (r == m - 1 || c == n - 1) {
            dfs(dfs, r, c, atlantic);
          }
        }
      }

      for (int r = 0; r < m; r++) {
        for (int c = 0; c < n; c++) {
          if (pacific[r][c] && atlantic[r][c]) {
            res.push_back({ r, c });
          }
        }
      }

      return res;
    }
};

