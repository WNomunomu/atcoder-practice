#include <bits/stdc++.h>
#include <climits>
#include <queue>
#include <utility>
using namespace std;

struct Path {
  int to;
  long long cost;
  Path(int v, long long b) : to(v), cost(b) {};   
};

void dijkstra(vector<vector<Path>>& graph, vector<long long>& A, int start, vector<long long>& dist) {
  int n = graph.size();
  priority_queue<pair<int, long long>, vector<pair<int, long long>>, greater<pair<int, long long>>> pq;

  dist[start] = A[start];
  pq.push(make_pair(start, dist[start]));

  while (!pq.empty()) {
    int v = pq.top().first;
    long long cost = pq.top().second;
    pq.pop();

    if (cost > dist[v]) continue;

    for (int i = 0; i < graph[v].size(); i++) {
      Path& p = graph[v][i];
      long long newDist = dist[v] + A[p.to] + p.cost;
      if (newDist < dist[p.to]) {
        dist[p.to] = newDist;
        pq.push(make_pair(p.to, dist[p.to]));
      }
    }
  }
}

int main() {
  int n, m;
  cin >> n >> m;

  vector<long long> A(n + 1);
  vector<vector<Path>> graph(n + 1);

  for (int i = 1; i <= n; i++) {
    long long a;
    cin >> a;
    A[i] = a;
  }

  for (int i = 0; i < m; i++) {
    int u, v;
    long long b;
    cin >> u >> v >> b;
    graph[u].push_back(Path(v, b));
    graph[v].push_back(Path(u, b));
  }
  
  vector<long long> dist(n + 1, LLONG_MAX);
  int start = 1;
  dijkstra(graph, A, start, dist);

  for (int i = 2; i <= n; i++) {
    if (i != 2) cout << " ";
    cout << dist[i];
  }
  cout << endl;

  return 0;
}

