#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> cards(n);
  for (int i = 0; i < n; i++) {
    cin >> cards[i];
  }
  sort(cards.begin(), cards.end());

  int x = 0;
  int y = 0;

  for (int i = 0; i < cards.size(); i++) {
    if (i % 2 == 0) {
      x += cards[i];
    }
    else {
      y += cards[i];
    }
  }

  if (x - y > 0) {
    cout << x - y << endl;
  }
  else {
    cout << y - x << endl;
  }

  return 0;
}
