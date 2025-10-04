#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

int main() {
  string x, y;

  cin >> x >> y;

  unordered_map<string, int> map;
  map["Ocelot"] = 0;
  map["Serval"] = 1;
  map["Lynx"] = 2;

  if (map[x] >= map[y]) cout << "Yes" << endl;
  else {
    cout << "No" << endl;
  }

  return 0;
}

