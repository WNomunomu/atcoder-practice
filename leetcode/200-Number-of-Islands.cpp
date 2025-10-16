#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int numIslands(vector<vector<char>>& grid) {
      int m = grid.size();
      int n = grid[0].size();
      vector<vector<bool>> isVisited(m, vector<bool>(n, false));
      vector<vector<int>> directions = {{ 0, 1 }, { 1, 0 }, { 0, -1 }, { -1, 0 }};

      int ans = 0;
      
      for (int r = 0; r < m; r++) {
        for (int c = 0; c < n; c++) {
          if (!isVisited[r][c] && grid[r][c] == '1') {
            dfs(r, c, grid, isVisited, directions);
            ans++;
          }
          else {
            isVisited[r][c] = true;
          }
        }
      }

      return ans;
    }
  private:
    void dfs(int r, int c, vector<vector<char>>& grid, vector<vector<bool>>& isVisited, vector<vector<int>>& directions) {
      isVisited[r][c] = true;

      for (vector<int>& direction : directions) {
        int nextRow = r + direction[0];
        int nextCol = c + direction[1];

        if (nextRow >= 0 && nextRow < grid.size() && nextCol >= 0 && nextCol < grid[0].size()) {
          if (!isVisited[nextRow][nextCol] && grid[nextRow][nextCol] == '1') {

            dfs(nextRow, nextCol, grid, isVisited, directions);
          }
        }
      }
    }
};

