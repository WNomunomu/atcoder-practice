#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    void solve(vector<vector<char>>& board) {
      int m = board.size();
      int n = board[0].size();

      vector<vector<bool>> isVisited(m, vector<bool>(n, false));

      vector<pair<int, int>> directions = {{ 0, 1 }, { 0, -1 }, { 1, 0 }, { -1, 0 }};

      auto dfs = [&](auto self, int r, int c) -> void {
        isVisited[r][c] = true;
        board[r][c] = '#';
        
        for (auto direction : directions) {
          int nr = r + direction.first;
          int nc = c + direction.second;

          if (nr >= 0 && nr < m && nc >= 0 && nc < n) {
            if (!isVisited[nr][nc] && board[nr][nc] == 'O') {
              self(self, nr, nc);
            }
          }
        }
      };

      for (int r = 0; r < m; r++) {
        if (r == 0 || r == m - 1) {
          for (int c = 0; c < n; c++) {
            if (board[r][c] == 'O') {
              dfs(dfs, r, c);
            }
          }
        }
        else {
          if (board[r][0] == 'O') {
            dfs(dfs, r, 0);
          }
          if (board[r][n - 1] == 'O') {
            dfs(dfs, r, n - 1);
          }
        }
      }

      for (int r = 0; r < m; r++) {
        for (int c = 0; c < n; c++) {
          if (board[r][c] == 'O') {
            board[r][c] = 'X';
          }
          else if (board[r][c] == '#') {
            board[r][c] = 'O';
          }
        }
      }
    }
};

