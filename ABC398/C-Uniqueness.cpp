#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

int main() {
  int n;
  cin >> n;
  
  unordered_map<long long, long long> map;
  unordered_map<long long, long long> number;
  set<long long> st;

  for (int i = 1; i <= n; i++) {
    int a;
    cin >> a;
    number[a] = i;
    map[a]++;

    if (map[a] > 1) {
      st.erase(a);
    }
    else {
      st.insert(a);
    }
  }

  if (st.empty()) cout << -1 << endl;
  else {
    cout << number[*st.rbegin()] << endl;
  }

  return 0;
}
