#include <bits/stdc++.h>
using namespace std;

class DisjointSet {
  public:
    vector<int> rank;
    vector<int> parent;

    DisjointSet() {}
    DisjointSet(int size) {
      rank.resize(size, 0);
      parent.resize(size, 0);
      for (int i = 0; i < size; i++) {
        makeSet(i);
      }
    }

    void makeSet(int x) {
      parent[x] = x;
      rank[x] = 0;
    }

    bool same(int x, int y) {
      return findSet(x) == findSet(y);
    }

    void unite(int x, int y) {
      link(findSet(x), findSet(y));
    }

    void link(int x, int y) {
      if (rank[x] > rank[y]) {
        parent[y] = x;
      }
      else {
        parent[x] = y;
        if (rank[x] == rank[y]) {
          rank[y]++;
        }
      }
    }

    int findSet(int x) {
      if (parent[x] != x) {
        parent[x] = findSet(parent[x]);
      }
      return parent[x];
    }
};

int main() {
  int n, q;
  cin >> n >> q;

  DisjointSet ds = DisjointSet(n);

  for (int i = 0; i < q; i++) {
    int command, x, y;
    cin >> command >> x >> y;
    if (command == 0) {
      ds.unite(x, y);
    }
    else if (command == 1) {
      if (ds.same(x, y)) {
        cout << 1 << endl;
      }
      else {
        cout << 0 << endl;
      }
    }
  }

  return 0;
}
