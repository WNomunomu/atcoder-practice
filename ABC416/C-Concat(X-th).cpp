#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, k, x;
  cin >> n >> k >> x;

  vector<string> S;
  vector<string> Ans;

  for (int i = 0; i < n; i++) {
    string s;
    cin >> s;
    S.push_back(s);
  }

  auto dfs = [&](auto self, string crr, int count) -> void {
    if (count == k) {
      Ans.push_back(crr);
      return;
    }

    for (string& s : S) {
      self(self, crr + s, count + 1);
    }
  };

  dfs(dfs, "", 0);

  sort(Ans.begin(), Ans.end());

  cout << Ans[x - 1] << endl;

  return 0;
}
