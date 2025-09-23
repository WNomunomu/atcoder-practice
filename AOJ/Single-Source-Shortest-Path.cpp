#include <iostream>
#include <utility>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

struct Edge {
  int to;
  int cost;
  Edge(int t, int c) : to(t), cost(c) {}
};

void dijkstra(vector<vector<Edge>>& graph, int start, vector<int>& dist) {
  int n = graph.size();
  priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

  dist[start] = 0;
  pq.push(make_pair(0, start));

  while (!pq.empty()) {
    int cost = pq.top().first;
    int v = pq.top().second;
    pq.pop();

    if (cost > dist[v]) continue;

    for (int i = 0; i < graph[v].size(); i++) {
      Edge& e = graph[v][i];
      if (dist[v] + e.cost < dist[e.to]) {
        dist[e.to] = dist[v] + e.cost;
        pq.push(make_pair(dist[e.to], e.to));
      }
    }
  }
}

int main() {
  int n;
  cin >> n;

  vector<vector<Edge>> graph(n);

  for (int i = 0; i < n; i++) {
    int u, k;
    cin >> u >> k;

    for (int j = 0; j < k; j++) {
      int v, c;
      cin >> v >> c;
      graph[u].push_back(Edge(v, c));
    }
  }

  vector<int> dist(n, INT_MAX);
  dijkstra(graph, 0, dist);

  for (int i = 0; i < n; i++) {
    cout << i << " " << dist[i] << endl;
  }

  return 0;
}

