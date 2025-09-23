#include <bits/stdc++.h>
#include <climits>
#include <utility>
using namespace std;


int main() {
  int r, c;
  cin >> r >> c;
  vector<vector<char>> graph(r, vector<char>(c));
  
  int sy, sx;
  cin >> sy >> sx;
  sy--; sx--;
  
  int gy, gx;
  cin >> gy >> gx;
  gy--; gx--;
  
  for (int i = 0; i < r; i++) {
    for (int j = 0; j < c; j++) {
      cin >> graph[i][j];
    }
  }
  
  vector<vector<int>> dist(r, vector<int>(c, -1));
  vector<vector<bool>> isVisited(r, vector<bool>(c, false));
  
  vector<vector<int>> directions = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
  
  queue<pair<int, int>> q;
  q.push(make_pair(sy, sx));
  isVisited[sy][sx] = true;

  dist[sy][sx] = 0;

  
  while (!q.empty()) {
    int y = q.front().first;
    int x = q.front().second;
    q.pop();
    
    for (vector<int>& direction : directions) {
      int nextY = y + direction[0];
      int nextX = x + direction[1];
      
      if (nextY >= 0 && nextY < r && nextX >= 0 && nextX < c) {
        if (!isVisited[nextY][nextX] && graph[nextY][nextX] == '.') {
          q.push(make_pair(nextY, nextX));
          isVisited[nextY][nextX] = true;
          dist[nextY][nextX] = dist[y][x] + 1;
        }
      }
    }
  }
  
  cout << dist[gy][gx] << endl;
  return 0;
}

