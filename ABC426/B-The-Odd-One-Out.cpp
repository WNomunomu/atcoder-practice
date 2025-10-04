#include <bits/stdc++.h>
#include <string>
#include <unordered_map>
using namespace std;

int main() {
  string s;
  cin >> s;

  unordered_map<char, int> map;
  set<char> st;

  char notAns;

  for (char c : s) {
    map[c]++;
    st.insert(c);
    if (map[c] > 1) {
      notAns = c;
    }
  }

  for (char c : st) {
    if (c != notAns) {
      cout << c << endl;
      break;
    } 
  }

  return 0;
}

