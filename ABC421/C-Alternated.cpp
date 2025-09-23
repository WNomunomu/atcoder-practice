#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  string s;
  cin >> s;

  long count1 = 0;
  long count2 = 0;

  int counter = 0;
  for (int i = 0; i < n + n; i++) {
    if (s[i] == 'A') {
      count1 += abs(i - 2 * counter);
      count2 += abs(i - (2 * counter + 1));
      counter++;
    }
  }

  cout << min(count1, count2) << endl;

  return 0;
}

