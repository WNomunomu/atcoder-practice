#include <bits/stdc++.h>
#include <string>
#include <unordered_map>
using namespace std;
#define int long long

signed main() {
  int n, k;
  cin >> n >> k;

  string s;
  cin >> s;

  unordered_map<string, int> map;

  for (int i = 0; i <= n - k; i++) {
    string subStr = s.substr(i, k);
    map[subStr]++;
  }

  int maxNum = 0;

  for (auto pair : map) {
    maxNum = max(maxNum, pair.second);
  }

  cout << maxNum << endl;

  vector<string> ans;

  for (auto pair : map) {
    if (pair.second == maxNum) {
      ans.push_back(pair.first);
    }
  }

  sort(ans.begin(), ans.end());

  for (int i = 0; i < ans.size(); i++) {
    if (i != 0) {
      cout << " ";
    }
    cout << ans[i];
  }

  cout << endl;

  return 0;
}

