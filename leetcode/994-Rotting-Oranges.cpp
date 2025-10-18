#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int orangesRotting(vector<vector<int>>& grid) {
      int m = grid.size();
      int n = grid[0].size();

      int ans = 0;

      vector<pair<int, int>> directions = {{ 0, 1 }, { 1, 0 }, { -1, 0 }, { 0, -1 }};
      vector<vector<int>> distanceFromRotten(m, vector<int>(n, 100));

      queue<pair<int, int>> q;

      for (int r = 0; r < m; r++) {
        for (int c = 0; c < n; c++) {
          if (grid[r][c] == 2) {
            q.push({r, c});
            distanceFromRotten[r][c] = 0;
          }
        }
      }

      bfs(q, grid, directions, distanceFromRotten);

      for (int r = 0; r < m; r++) {
        for (int c = 0; c < n; c++) {
          if (distanceFromRotten[r][c] != 100) {
            ans = max(distanceFromRotten[r][c], ans);
          }
          if (grid[r][c] == 1 && distanceFromRotten[r][c] == 100) {
            return -1;
          }
        }
      }

      return ans;
    }
  private:
    void bfs(queue<pair<int, int>>& q, vector<vector<int>>& grid, vector<pair<int, int>>& directions, vector<vector<int>>& distanceFromRotten) {
      int m = grid.size();
      int n = grid[0].size();

      while (!q.empty()) {
        auto [r, c] = q.front();
        q.pop();

        for (pair<int, int>& direction : directions) {
          int nextRow = r + direction.first;
          int nextCol = c + direction.second;

          if (nextRow >= 0 && nextRow < m && nextCol >= 0 && nextCol < n) {
            if (grid[nextRow][nextCol] == 1 && distanceFromRotten[nextRow][nextCol] == 100) {
              distanceFromRotten[nextRow][nextCol] = distanceFromRotten[r][c] + 1;
              q.push({ nextRow, nextCol });
            }
          }
        }
      }
    }
};

