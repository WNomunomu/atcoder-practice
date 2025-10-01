#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, m, q;
  cin >> n >> m >> q;
  set<int> adminUser;
  unordered_map<int, set<int>> authority;

  for (int i = 0; i < q; i++) {
    int command, x;
    cin >> command >> x;

    if (command == 1) {
      int y;
      cin >> y;
      authority[x].insert(y);
    }
    else if (command == 2) {
      adminUser.insert(x);
    }
    else if (command == 3) {
      int y;
      cin >> y;

      if (adminUser.contains(x)) {
        cout << "Yes" << endl;
        continue;
      }

      if (authority[x].contains(y)) {
        cout << "Yes" << endl;
      }
      else {
        cout << "No" << endl;
      }
    }
  }

  return 0;
}

