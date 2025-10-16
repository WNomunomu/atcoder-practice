#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
      int m = grid.size();
      int n = grid[0].size();

      vector<vector<bool>> isVisited(m, vector<bool>(n, false));
      vector<pair<int, int>> directions = {{ 0, 1 }, { 1, 0 }, { -1, 0 }, { 0, -1 }};

      int maxArea = 0;

      for (int r = 0; r < m; r++) {
        for (int c = 0; c < n; c++) {
          if (!isVisited[r][c] && grid[r][c] == 1) {
            int area = 0;
            dfs(r, c, grid, isVisited, directions, area);
            maxArea = max(maxArea, area);
          }
          else {
            isVisited[r][c] = true;
          }
        }
      }

      return maxArea;
    }
  private:
    void dfs(int r, int c, vector<vector<int>>& grid, vector<vector<bool>>& isVisited, vector<pair<int, int>>& directions, int& area) {
      isVisited[r][c] = true;
      area++;

      for (pair<int, int>& direction : directions) {
        int nextRow = r + direction.first;
        int nextCol = c + direction.second;

        if (nextRow >= 0 && nextRow < grid.size() && nextCol >= 0 && nextCol < grid[0].size()) {
          if (!isVisited[nextRow][nextCol] && grid[nextRow][nextCol] == 1) {
            dfs(nextRow, nextCol, grid, isVisited, directions, area);
          }
        }
      }
    }
};

